#include "VertexBuffer.h"

namespace engine
{
    VertexBuffer::VertexBuffer()
    {
        glCreateBuffers(1, &m_Buffer);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &m_Buffer);
    }

    void VertexBuffer::bufferData(const void *data, GLsizeiptr size)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    }

    void VertexBuffer::bufferSubData(const void *data, GLsizeiptr size)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

    void VertexBuffer::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_Buffer);
    }

    void VertexBuffer::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

} // namespace engine