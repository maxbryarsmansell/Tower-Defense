#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

#include <vector>
#include <string>

namespace engine
{
    class VertexBuffer
    {
    private:
        GLuint m_Buffer;

    public:
        VertexBuffer();
        ~VertexBuffer();

        void bufferData(const void *data, GLsizeiptr size);
        void bufferSubData(const void *data, GLsizeiptr size);

        void bind();
        void unbind();
    };
} // namespace engine

#endif