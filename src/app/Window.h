#ifndef WINDOW_H
#define WINDOW_H

#include "Event.h"

#include <GLFW/glfw3.h>

#include <string>
#include <functional>

namespace engine
{
	struct WindowData
	{
		std::string title;
		int width, height;

		std::function<void(Event &e)> callback;
	};

	class Window
	{

	private:
		GLFWwindow *m_Window;
		WindowData m_Data;

	public:
		Window(int width, int height, std::string title);
		~Window();

		GLFWwindow *getWindow() { return m_Window; }

		void setCallback(const std::function<void(Event &e)> &callback) { m_Data.callback = callback; }
		void setTitle(std::string title) { glfwSetWindowTitle(m_Window, title.c_str()); }
		void setVSync(bool state) { glfwSwapInterval(state ? 1 : 0); }

		void onUpdate();
		void onShutdown();
	};
} // namespace engine

#endif