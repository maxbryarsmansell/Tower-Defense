#include "Shader.h"

#include <iostream>
#include <fstream>

namespace engine
{

    Shader::Shader(const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        compile(vertexSrc, fragmentSrc);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_Program);
    }

    void Shader::bind()
    {
        glUseProgram(m_Program);
    }

    void Shader::unbind()
    {
        glUseProgram(0);
    }

    void Shader::setUniformFloat(const std::string &name, float value)
    {
        glUseProgram(m_Program);

        GLint loc = glGetUniformLocation(m_Program, name.c_str());
        glUniform1f(loc, value);
    }

    void Shader::compile(const std::string &vertexSrc, const std::string &fragmentSrc)
    {
        int success;
        char infoLog[512];
        const GLchar *vertex_c_str = vertexSrc.c_str();
        const GLchar *fragment_c_str = fragmentSrc.c_str();

        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vertex_c_str, NULL);
        glCompileShader(vertex);

        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            std::cout << "[ERROR]: Vertex Shader Compilation Failed" << std::endl
                      << infoLog << std::endl;
        };

        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fragment_c_str, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            std::cout << "[ERROR]: Fragment Shader Compilation Failed" << std::endl
                      << infoLog << std::endl;
        };

        GLuint program = glCreateProgram();
        glAttachShader(program, vertex);
        glAttachShader(program, fragment);

        glLinkProgram(program);

        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            std::cout << "[ERROR]: Program Linking Failed" << std::endl
                      << infoLog << std::endl;
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        m_Program = program;
    }

    std::string Shader::load(const std::string &filepath)
    {
        std::string result;
        std::ifstream file(filepath, std::ios::in | std::ios::binary);

        if (file.is_open())
        {
            file.seekg(0, std::ios::end);
            size_t size = file.tellg();
            if (size != -1)
            {
                result.resize(size);
                file.seekg(0, std::ios::beg);
                file.read(&result[0], size);
            }
            else
            {
                std::cout << "Failed to read from file '" << filepath << "'." << std::endl;
            }
        }
        else
        {
            std::cout << "Failed to open file '" << filepath << "'." << std::endl;
        }

        return result;
    }

} // namespace engine
