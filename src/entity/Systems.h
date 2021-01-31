#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "entity/Components.h"

#include "graphics/Renderer.h"

#include "app/Input.h"

#include <entt/entt.hpp>
#include <memory>
#include <cmath>

namespace engine
{
    class RenderSystem
    {
    private:
        std::shared_ptr<Renderer> m_Renderer;

    public:
        RenderSystem(std::shared_ptr<Renderer> renderer) : m_Renderer(renderer) {}

        void update(entt::registry &registry);
    };

    class PhysicsSystem
    {
    public:
        void update(entt::registry &registry, float delta);
    };

    class ControlSystem
    {
    private:
        std::shared_ptr<Input> m_Input;

    public:
        ControlSystem(std::shared_ptr<Input> input) : m_Input(input) {}

        void update(entt::registry &registry);
    };

    void RenderSystem::update(entt::registry &registry)
    {
        auto view = registry.view<const Transform, const Graphics>();

        m_Renderer->begin();

        for (auto entity : view)
        {
            auto &transform = view.get<const Transform>(entity);
            auto &graphics = view.get<const Graphics>(entity);

            m_Renderer->submit(transform.x, transform.y, 0.5f, 0.5f);
        }

        m_Renderer->end();
    }

    void PhysicsSystem::update(entt::registry &registry, float delta)
    {
        auto view = registry.view<Transform, Physics>();

        for (auto entity : view)
        {
            auto &transform = view.get<Transform>(entity);
            auto &physics = view.get<Physics>(entity);

            physics.vx += physics.ax * delta;
            physics.vy += physics.ay * delta;
            physics.vz += physics.az * delta;

            transform.x += physics.vx * delta;
            transform.y += physics.vy * delta;
            transform.z += physics.vz * delta;
        }
    }

    void ControlSystem::update(entt::registry &registry)
    {
        auto view = registry.view<Physics>();

        for (auto entity : view)
        {
            auto &physics = view.get<Physics>(entity);

            if (m_Input->isKeyPressed(GLFW_KEY_D))
            {
                physics.ax = 10.0f;
            }
            else if (m_Input->isKeyPressed(GLFW_KEY_A))
            {
                physics.ax = -10.0f;
            }
            else
            {
                physics.ax = 0.0f;
            }
        }
    }

} // namespace engine

#endif
