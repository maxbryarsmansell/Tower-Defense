#ifndef INPUT_H
#define INPUT_H

#include "app/Window.h"

#include <memory>

namespace engine
{
    class Input
    {
    private:
        std::shared_ptr<Window> m_Window;

    public:
        Input(std::shared_ptr<Window> window) : m_Window(window) {}

        bool isKeyPressed(int keyCode)
        {
            return glfwGetKey(m_Window->getWindow(), keyCode) == GLFW_PRESS;
        }
    };
} // namespace engine

#endif