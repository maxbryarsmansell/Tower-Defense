#include "Renderer.h"

#include <iostream>

namespace engine
{
    Renderer::Renderer()
    {
        std::string vertex_src = engine::Shader::load("res/basic.vs");
        std::string fragment_src = engine::Shader::load("res/basic.fs");

        m_Shader = std::make_unique<Shader>(vertex_src, fragment_src);

        m_VertexBuffer.buffer_data(nullptr, MAX_BYTES);
        m_VertexArray.set_vertex_buffer(m_VertexBuffer);

        m_Vertices = new Renderer::Vertex[MAX_BYTES];
        m_Start = m_Vertices;
    }

    Renderer::~Renderer()
    {
        delete[] m_Start;
    }

    void Renderer::begin()
    {
        m_Vertices = m_Start;
        m_Count = 0;
    }

    void Renderer::end()
    {
        flush();
    }

    void Renderer::flush()
    {
        if (m_Count > MAX_VERTICES)
        {
            std::cout << "[WARNING]: Attempted to flush too many vertices (" << m_Count << ")." << std::endl;
            return;
        }

        // std::cout << m_Count << std::endl;

        GLsizei size = m_Count * VERTEX_SIZE * sizeof(float);
        m_VertexBuffer.buffer_sub_data(m_Start, size);

        m_Shader->bind();
        m_VertexArray.bind();
        glDrawArrays(GL_TRIANGLES, 0, m_Count);
    }

    void Renderer::submit(float x, float y, float width, float height)
    {
        if (m_Count + 6 > MAX_VERTICES)
        {
            flush();
            begin();
        }

        m_Vertices->x = x - width;
        m_Vertices->y = y - height;
        m_Vertices->z = 0.0f;
        m_Vertices->r = 1.0f;
        m_Vertices->g = 0.0f;
        m_Vertices->b = 0.0f;

        m_Vertices++;
        m_Count++;

        m_Vertices->x = x - width;
        m_Vertices->y = y + height;
        m_Vertices->z = 0.0f;
        m_Vertices->r = 1.0f;
        m_Vertices->g = 0.0f;
        m_Vertices->b = 0.0f;

        m_Vertices++;
        m_Count++;

        m_Vertices->x = x + width;
        m_Vertices->y = y - height;
        m_Vertices->z = 0.0f;
        m_Vertices->r = 1.0f;
        m_Vertices->g = 0.0f;
        m_Vertices->b = 0.0f;

        m_Vertices++;
        m_Count++;

        m_Vertices->x = x + width;
        m_Vertices->y = y - height;
        m_Vertices->z = 0.0f;
        m_Vertices->r = 1.0f;
        m_Vertices->g = 0.0f;
        m_Vertices->b = 0.0f;

        m_Vertices++;
        m_Count++;

        m_Vertices->x = x - width;
        m_Vertices->y = y + height;
        m_Vertices->z = 0.0f;
        m_Vertices->r = 1.0f;
        m_Vertices->g = 0.0f;
        m_Vertices->b = 0.0f;

        m_Vertices++;
        m_Count++;

        m_Vertices->x = x + width;
        m_Vertices->y = y + height;
        m_Vertices->z = 0.0f;
        m_Vertices->r = 1.0f;
        m_Vertices->g = 0.0f;
        m_Vertices->b = 0.0f;

        m_Vertices++;
        m_Count++;

        // float vertices[] =
        //     {x - 0.5f, y - 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        //      x - 0.5f, y + 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        //      x + 0.5f, y - 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,

        //      x + 0.5f, y - 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        //      x - 0.5f, y + 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        //      x + 0.5f, y + 0.5f, 0.0f, 1.0f, 0.0f, 0.0f};
    }
} // namespace engine