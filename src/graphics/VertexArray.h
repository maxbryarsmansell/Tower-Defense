#pragma once

#include "VertexBuffer.h"

#include <glad/glad.h>

#include <memory>

namespace engine
{
    class VertexArray
    {
    private:
        GLuint m_Array;

    public:
        VertexArray();
        ~VertexArray();

        void set_vertex_buffer(VertexBuffer& vertex_buffer);

        void bind();
        void unbind();
    };

} // namespace engine