#ifndef SYSTEMS_H
#define SYSTEMS_H

#include "entity/Components.h"

#include "graphics/Renderer.h"

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

    void PhysicsSystem::update(entt::registry &registry)
    {
        auto view = registry.view<Transform, const Physics>();

        for (auto entity : view)
        {
            auto &transform = view.get<Transform>(entity);
            auto &physics = view.get<const Physics>(entity);

            transform.x += physics.vx;
            transform.y += physics.vy;
        }
    }

} // namespace engine

#endif
