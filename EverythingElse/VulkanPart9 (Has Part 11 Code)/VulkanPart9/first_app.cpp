#include "first_app.hpp"

#include "simple_render_system.hpp"

//std 
#include <stdexcept>
#include <array>

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include<glm/gtc/constants.hpp>

namespace lve
{
	FirstApp::FirstApp()
	{
		loadGameObjects();
	}

	FirstApp::~FirstApp() {}

	void lve::FirstApp::run()
	{
		SimpleRenderSystem simpleRenderSystem{ lveDevice, lveRenderer.getSwapChainRenderPass() };

		while (!lveWindow.shouldClose())
		{
			glfwPollEvents();

			if (auto commandBuffer = lveRenderer.beginFrame())
			{
				lveRenderer.beginSwapChainRenderPass(commandBuffer);
				simpleRenderSystem.renderGameObjects(commandBuffer, gameObjects);
				lveRenderer.endSwapChainRenderPass(commandBuffer);
				lveRenderer.endFrame();
			}
		}
	}

	void FirstApp::loadGameObjects()
	{
		std::vector<LveModel::Vertex> vertices{
			{{0.0f, -0.5f}, {1.0f,0,0}},
			{{0.5f, 0.5f}, {0,1.0f,0}},
			{{-0.5f, 0.5f}, {0,0,1.0f}}
		};

		auto lveModel = std::make_shared<LveModel>(lveDevice, vertices);

		auto triangle = LveGameObject::createGameObject();
		triangle.model = lveModel;
		triangle.color = { .1f, .8f, .1f };
		triangle.transform2d.translation.x = .2f;
		triangle.transform2d.scale = { 2.f, 0.5f };
		triangle.transform2d.rotation = { 2.f * glm::two_pi<float>() };

		gameObjects.push_back(std::move(triangle));
	}
}

