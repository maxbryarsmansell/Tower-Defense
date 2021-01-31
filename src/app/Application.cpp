#include "app/Application.h"

#include <glad/glad.h>

#include <functional>

namespace engine
{

	Application::Application()
		: m_Running(false), m_Window(std::make_shared<Window>(1280, 720, "Window"))
	{
		m_Window->setCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}

	Application::Application(int width, int height, std::string title)
		: m_Running(false), m_Window(std::make_shared<Window>(width, height, title))
	{
		m_Window->setCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	}

	void Application::onEvent(Event &event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
		dispatcher.dispatch<WindowResizeEvent>(std::bind(&Application::onWindowResize, this, std::placeholders::_1));

		for (auto it = m_Layers.rbegin(); it != m_Layers.rend(); ++it)
		{
			if (event.handled)
				break;

			(*it)->onEvent(event);
		}
	}

	void Application::run()
	{
		m_Running = true;

		double delta = 0, last = 0, current = 0;

		while (m_Running)
		{
			current = glfwGetTime();
			delta = current - last;
			last = current;

			for (auto &layer : m_Layers)
				layer->onUpdate((float)delta);

			m_Window->onUpdate();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}

	void Application::pushLayer(std::shared_ptr<Layer> layer)
	{
		m_Layers.push_back(layer);
	}

	// TODO: Move these callbacks.

	bool Application::onWindowClose(WindowCloseEvent &event)
	{
		m_Running = false;
		return false;
	}

	bool Application::onWindowResize(WindowResizeEvent &event)
	{
		glViewport(0, 0, event.width, event.height);
		return false;
	}

} // namespace engine