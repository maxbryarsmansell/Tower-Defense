#include "Window.h"

#include <glad/glad.h>

#include <iostream>
#include <stdio.h>

namespace engine
{
	Window::~Window()
	{
		onShutdown();
	}

	Window::Window(int width, int height, std::string title)
	{
		m_Data.width = width;
		m_Data.height = height;
		m_Data.title = title;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwSetErrorCallback([](int error, const char *description) {
			std::cout << "[GLFW ERROR]: " << description << "." << std::endl;
		});

		m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (!m_Window)
			std::cout << "[GLFW ERROR]: Failed to create GLFW window." << std::endl;

		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			std::cout << "[GLAD ERROR]: Could not load OpenGL." << std::endl;

		glfwSetWindowUserPointer(m_Window, &m_Data);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			WindowCloseEvent e;
			data.callback(e);
		});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowResizeEvent e(width, height);
			data.callback(e);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			KeyPressedEvent e(key, mods);
			data.callback(e);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			MousePressedEvent e(button, action, mods);
			data.callback(e);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xpos, double ypos) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			MouseMovedEvent e(xpos, ypos);
			data.callback(e);
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xoffset, double yoffset) {
			WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

			MouseScrolledEvent e(xoffset, yoffset);
			data.callback(e);
		});
	}

	void Window::onUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Window::onShutdown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

} // namespace engine
