#ifndef APPLICATION_H
#define APPLICATION_H

#include "app/Layer.h"
#include "app/Window.h"

#include <memory>
#include <vector>

namespace engine
{
	class Application
	{
	private:
		bool m_Running;
		std::shared_ptr<Window> m_Window;
		std::vector<std::shared_ptr<Layer>> m_Layers;

	public:
		Application();
		Application(int width, int height, std::string title);

		std::shared_ptr<Window> getWindow() { return m_Window; }

		void setTitle(std::string title) { m_Window->setTitle(title); }

		void run();

		void pushLayer(std::shared_ptr<Layer> layer);

	private:
		void onEvent(Event &e);
		bool onWindowClose(WindowCloseEvent &e);
		bool onWindowResize(WindowResizeEvent &e);
	};

} // namespace engine

#endif