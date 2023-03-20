#include "lve_pipeline.hpp"
#include <fstream>
#include <iostream>

namespace lve
{
	lve::LvePipeline::LvePipeline(
		LveDevice& device,
		const std::string& vertFilePath,
		const std::string& fragFilepath,
		const PipelineConfigInfo& configInfo)
		:lveDevice{ device }
	{
		createGraphicsPipeLine(vertFilePath, fragFilepath, configInfo);
	}

	LvePipeline::~LvePipeline()
	{
	}

	PipelineConfigInfo LvePipeline::defaultPipelineCongfigInfo(uint32_t width, uint32_t height)
	{
		PipelineConfigInfo configInfo{};
		return configInfo;
	}

	std::vector<char> lve::LvePipeline::readfile(const std::string& filepath)
	{
		std::ifstream file{ filepath, std::ios::ate | std::ios::binary };
		if(!file.is_open())
		{
			throw std::runtime_error("failed to open file: " + filepath);
		}

		// Read File Size
		size_t fileSize = static_cast<size_t>(file.tellg());

		std::vector<char> buffer(fileSize);

		// Load data from 0 -> file size into buffer
		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}

	void lve::LvePipeline::createGraphicsPipeLine(
		const std::string& vertFilePath,
		const std::string& fragFilePath,
		const PipelineConfigInfo& configInfo)
	{
		auto vertCode = readfile(vertFilePath);
		auto fragCode = readfile(fragFilePath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
		std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
	}

	void LvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if(vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create shader module");
		}
	}
}

