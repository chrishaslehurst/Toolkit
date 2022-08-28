#include "Shader.h"
#include "Utils.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace tk
{
    Shader::Shader(const char* filepath, ShaderType type)
    {
        std::string shaderSource = utilities::LoadFile(filepath);
        // #todo-ch 10/04/2022:can we improve this?
        const char *shaderSourceAsCharArray = shaderSource.c_str();

        switch (type)
        {
        case ShaderType::Vertex:
            shaderIndex = glCreateShader(GL_VERTEX_SHADER);
            break;
        case ShaderType::Fragment:
            shaderIndex = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        case ShaderType::Geometry:
            break;
        case ShaderType::Compute:
            break;
        default:
            break;
        }

        glShaderSource(shaderIndex, 1, &shaderSourceAsCharArray, nullptr);
        glCompileShader(shaderIndex);

        int success;
        char infoLog[512];
        glGetShaderiv(shaderIndex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shaderIndex, 512, NULL, infoLog);
            TK_CORE_ERROR("Shader compilation failed:\n {}", infoLog);
        }
    }

    Shader::~Shader() 
    { 
        glDeleteShader(shaderIndex);
    }

} // namespace toolkit
