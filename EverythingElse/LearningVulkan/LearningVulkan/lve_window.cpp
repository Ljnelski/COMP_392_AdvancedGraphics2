#include "lve_window.hpp"

#define GFLW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>

namespace lve
{
	lve::LveWindow::LveWindow(int w, int h, std::string name) : width {w}, height {h}, windowName{name}
	{
		initWindow();
	}

	LveWindow::~LveWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create windows surface");
		}
	}

	void lve::LveWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
		
	}
}


