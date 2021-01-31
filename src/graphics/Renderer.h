#ifndef RENDERER_H
#define RENDERER_H

#include "graphics/Shader.h"
#include "graphics/VertexArray.h"
#include "graphics/VertexBuffer.h"

#include <memory>

namespace engine
{
    static const int MAX_VERTICES = 1024;
    static const int VERTEX_SIZE = 6;
    static const int MAX_BYTES = MAX_VERTICES * VERTEX_SIZE * sizeof(float);

    class Renderer
    {
        struct Vertex
        {
            float x, y, z, r, g, b;
        };

    private:
        std::shared_ptr<Shader> m_Shader;

        VertexArray m_VertexArray;
        VertexBuffer m_VertexBuffer;

        Vertex *m_Vertices;
        Vertex *m_Start;
        int m_Count = 0;

    private:
        void flush();

    public:
        Renderer();
        ~Renderer();

        void begin();
        void end();

        void submit(float x, float y, float width, float height);
        // void submit(const Renderable& renderable);
    };
} // namespace engine

#endif