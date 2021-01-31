#include "VertexArray.h"

namespace engine
{

    VertexArray::VertexArray()
    {
        glCreateVertexArrays(1, &m_Array);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_Array);
    }

    void VertexArray::setVertexBuffer(VertexBuffer& vertexBuffer)
    {
        glBindVertexArray(m_Array);

        vertexBuffer.bind();

        // Predefined Layout:
        // vec3 position
        // vec3 colour

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    }

    void VertexArray::bind()
    {
        glBindVertexArray(m_Array);
    }

    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    }

} // namespace engine