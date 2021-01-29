#pragma once

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

        void buffer_data(const void *data, GLsizeiptr size);
        void buffer_sub_data(const void *data, GLsizeiptr size);

        void bind();
        void unbind();
    };

} // namespace engine