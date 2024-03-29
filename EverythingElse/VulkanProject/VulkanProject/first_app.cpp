#include "first_app.hpp"

#include "keyboard_movement_controller.hpp"
#include "lve_camera.hpp"
#include "lve_buffer.hpp"
#include "simple_render_system.hpp"
#include "point_light_system.hpp"

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

// std
#include <array>
#include <cassert>
#include <chrono>
#include <stdexcept>
#include "lve_frame_info.hpp"
#include "lve_animation.hpp"

namespace lve
{
	struct GlobalUbo
	{
		glm::mat4 projection{ 1.f };
		glm::mat4 view{ 1.f };
		glm::vec4 ambientLightColor{ 1.f, 1.f, 1.f, 0.02f };
		glm::vec3 lightPosition{ -1.f };
		alignas(16) glm::vec4 lightColor{ 1.f };
	};

	FirstApp::FirstApp()
	{
		globalPool = LveDescriptorPool::Builder(lveDevice)
			.setMaxSets(LveSwapChain::MAX_FRAMES_IN_FLIGHT)
			.addPoolSize(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, LveSwapChain::MAX_FRAMES_IN_FLIGHT)
			.build();
		loadGameObjects();
	}

	FirstApp::~FirstApp() {}

	void FirstApp::run()
	{
		std::vector<std::unique_ptr<LveBuffer>> uboBuffers(LveSwapChain::MAX_FRAMES_IN_FLIGHT);
		for (int i = 0; i < uboBuffers.size(); i++)
		{
			uboBuffers[i] = std::make_unique<LveBuffer>(lveDevice,
				sizeof(GlobalUbo),
				1,
				VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
				VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);

			uboBuffers[i]->map();
		}

		auto globalSetLayout = LveDescriptorSetLayout::Builder(lveDevice)
			.addBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_ALL_GRAPHICS)
			.build();

		std::vector<VkDescriptorSet> globalDescriptorSets(LveSwapChain::MAX_FRAMES_IN_FLIGHT);
		for (int i = 0; i < globalDescriptorSets.size(); i++)
		{
			auto bufferInfo = uboBuffers[i]->descriptorInfo();
			LveDescriptorWriter(*globalSetLayout, *globalPool)
				.writeBuffer(0, &bufferInfo)
				.build(globalDescriptorSets[i]);
		}

		SimpleRenderSystem simpleRenderSystem{
			lveDevice,
			lveRenderer.getSwapChainRenderPass(),
			globalSetLayout->getDescriptorSetLayout()
		};
		PointLightSystem pointLightSystem{
			lveDevice,
			lveRenderer.getSwapChainRenderPass(),
			globalSetLayout->getDescriptorSetLayout()
		};
		LveCamera camera{};

		auto viewerObject = LveGameObject::createGameObject();
		viewerObject.transform.translation.z = -2.5f;
		KeyboardMovementController cameraController{};

		auto currentTime = std::chrono::high_resolution_clock::now();

		while (!lveWindow.shouldClose())
		{
			glfwPollEvents();

			auto newTime = std::chrono::high_resolution_clock::now();
			float frameTime =
				std::chrono::duration<float, std::chrono::seconds::period>(newTime - currentTime).count();
			currentTime = newTime;

			cameraController.moveInPlaneXZ(lveWindow.getGLFWwindow(), frameTime, viewerObject);
			camera.setViewYXZ(viewerObject.transform.translation, viewerObject.transform.rotation);

			// Run animation			
			//animation.calculateTransform(frameTime);

			for (auto animation: animations)
			{
				animation->calculateTransform(frameTime);
			}

			float aspect = lveRenderer.getAspectRatio();
			camera.setPerspectiveProjection(glm::radians(50.f), aspect, 0.1f, 100.f);

			if (auto commandBuffer = lveRenderer.beginFrame())
			{
				int frameIndex = lveRenderer.getFrameIndex();
				FrameInfo frameInfo{ frameIndex, frameTime, commandBuffer, camera, globalDescriptorSets[frameIndex], gameObjects };

				// update
				GlobalUbo ubo{};
				ubo.projection = camera.getProjection();
				ubo.view = camera.getView();
				uboBuffers[frameIndex]->writeToBuffer(&ubo);
				uboBuffers[frameIndex]->flush();

				// render
				lveRenderer.beginSwapChainRenderPass(commandBuffer);
				simpleRenderSystem.renderGameObjects(frameInfo);
				pointLightSystem.render(frameInfo);
				lveRenderer.endSwapChainRenderPass(commandBuffer);
				lveRenderer.endFrame();
			}
		}
		vkDeviceWaitIdle(lveDevice.device());
	}

	void FirstApp::loadGameObjects()
	{
		animations = {};

		std::shared_ptr<LveModel> lveModel =
			LveModel::createModelFromFile(lveDevice, "models/flat_vase.obj");
		auto flatVase = LveGameObject::createGameObject();
		flatVase.model = lveModel;
		flatVase.transform.translation = { -.5f, .5f, 0.f };
		flatVase.transform.scale = { 3.f, 1.5f, 3.f };
		gameObjects.emplace(flatVase.getId(), std::move(flatVase));

		lveModel = LveModel::createModelFromFile(lveDevice, "models/smooth_vase.obj");
		auto smoothVase = LveGameObject::createGameObject();
		smoothVase.model = lveModel;
		smoothVase.transform.translation = { .5f, .5f, 0.f };
		smoothVase.transform.scale = { 3.f, 1.5f, 3.f };
		gameObjects.emplace(smoothVase.getId(), std::move(smoothVase));
		animations.push_back(new LveAnimation(&gameObjects.at(smoothVase.getId()), WOBBLE));
		

		lveModel = LveModel::createModelFromFile(lveDevice, "models/quad.obj");
		auto floor = LveGameObject::createGameObject();
		floor.model = lveModel;
		floor.transform.translation = { 0.f, .5f, 0.f };
		floor.transform.scale = { 3.f, 1.f, 3.f };
		gameObjects.emplace(floor.getId(), std::move(floor));

		lveModel = LveModel::createModelFromFile(lveDevice, "models/cube.obj");
		auto cube = LveGameObject::createGameObject();
		cube.model = lveModel;
		cube.transform.translation = { 0.f, .3f, 1.5f };
		cube.transform.scale = { .2f, .2f, .2f };
		cube.transform.rotation = { 0.f, 1.f, 0.f};
		gameObjects.emplace(cube.getId(), std::move(cube));
		animations.push_back(new LveAnimation(&gameObjects.at(cube.getId()), RISE_AND_FALL));

		lveModel = LveModel::createModelFromFile(lveDevice, "models/Brother_Previs_1.0.obj");
		auto brother = LveGameObject::createGameObject();
		brother.model = lveModel;
		brother.transform.translation = { 1.f, .3f, 1.5f };
		brother.transform.scale = { 1.f, 1.f, 1.f };
		brother.transform.rotation = { 0.f, 0.f, 0.f };
		gameObjects.emplace(brother.getId(), std::move(brother));
		animations.push_back(new LveAnimation(&gameObjects.at(brother.getId()), WOBBLE));
				
		lveModel = LveModel::createModelFromFile(lveDevice, "models/kid.obj");
		auto kid = LveGameObject::createGameObject();
		kid.model = lveModel;
		kid.transform.translation = { -1.f, .3f, 1.5f };
		kid.transform.scale = { .3f, .3f, .3f };
		kid.transform.rotation = {0.f, 0.f, 0.f };
		gameObjects.emplace(kid.getId(), std::move(kid));
		animations.push_back(new LveAnimation(&gameObjects.at(kid.getId()), GROW_AND_SHRINK));
	}
}  // namespace lve