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
        Shader(const std::string &vertex_src, const std::string &fragment_src);
        ~Shader();

        void bind();
        void unbind();

        void set_uniform_float(const std::string &name, float value);

    private:
        void compile(const std::string &vertex_src, const std::string &fragment_src);

    public:
        static std::string load(const std::string &filepath);
    };

} // namespace engine

#endif