#include "app/Application.h"
#include "app/Input.h"

#include "entity/Systems.h"

#include <entt/entt.hpp>

#include <iostream>
#include <cmath>

class TestLayer : public engine::Layer
{
private:
    std::shared_ptr<engine::Input> m_Input;
    std::shared_ptr<engine::Renderer> m_Renderer;

    entt::registry m_Registry;

    engine::RenderSystem m_Render;
    engine::PhysicsSystem m_Physics;
    engine::ControlSystem m_Control;

public:
    TestLayer(std::shared_ptr<engine::Window> window)
        : m_Input(std::make_shared<engine::Input>(window)), m_Renderer(std::make_shared<engine::Renderer>()),
            m_Render(m_Renderer), m_Control(m_Input)
    {
        auto entity = m_Registry.create();
        m_Registry.emplace<engine::Transform>(entity, 0.0f, 0.0f, 0.0f);
        m_Registry.emplace<engine::Graphics>(entity, 0.0f, 0.0f, 0.0f, 0.0f);
        m_Registry.emplace<engine::Physics>(entity, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    }

    virtual void onUpdate(float delta) override;
    virtual void onEvent(engine::Event &event) override;
};

void TestLayer::onEvent(engine::Event &event)
{
}

void TestLayer::onUpdate(float delta)
{
    m_Control.update(m_Registry);
    m_Physics.update(m_Registry, delta);
    m_Render.update(m_Registry);
}

int main()
{
    engine::Application app(1280, 720, "Window");
    app.pushLayer(std::make_shared<TestLayer>(app.getWindow()));
    app.run();

    return 0;
}