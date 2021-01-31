#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>

namespace engine
{
    class Shader
    {
    private:
        GLuint m_Program;

    public:
        Shader(const std::string &vertexSrc, const std::string &fragmentSrc);
        ~Shader();

        void bind();
        void unbind();

        void setUniformFloat(const std::string &name, float value);

    private:
        void compile(const std::string &vertexSrc, const std::string &fragmentSrc);

    public:
        static std::string load(const std::string &filepath);
    };

} // namespace engine

#endif