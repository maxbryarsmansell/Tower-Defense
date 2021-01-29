#include "graphics/Renderer.h"
#include "graphics/Shader.h"

#include "entity/Components.h"
#include "entity/Systems.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// #include <entt/entt.hpp>

#include <iostream>
#include <cmath>

// settings
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

void on_resize(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(window, &on_resize);

    glfwMakeContextCurrent(window);

    // glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);
    {
        auto renderer = std::make_shared<engine::Renderer>();

        entt::registry registry;

        engine::RenderSystem render(renderer);
        engine::PhysicsSystem physics;

        const auto entity1 = registry.create();
        registry.emplace<engine::Transform>(entity1, 0.0f, 0.0f, 0.0f);
        // registry.emplace<engine::Physics>(entity1, 0.001f, 0.002f, 0.0f);
        registry.emplace<engine::Graphics>(entity1);

        const auto entity2 = registry.create();
        registry.emplace<engine::Transform>(entity2, 0.5f, 0.2f, 0.0f);
        // registry.emplace<engine::Physics>(entity2, 0.001f, 0.002f, 0.0f);
        registry.emplace<engine::Graphics>(entity2);

        // render loop
        // -----------
        while (!glfwWindowShouldClose(window))
        {
            // input
            // -----
            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);

            glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            physics.update(registry);
            render.update(registry);

            // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
            // -------------------------------------------------------------------------------
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    glfwDestroyWindow(window);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();

    return 0;
}