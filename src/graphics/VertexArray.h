#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "VertexBuffer.h"

#include <glad/glad.h>

namespace engine
{
    class VertexArray
    {
    private:
        GLuint m_Array;

    public:
        VertexArray();
        ~VertexArray();

        void setVertexBuffer(VertexBuffer& vertexBuffer);

        void bind();
        void unbind();
    };
} // namespace engine

#endif