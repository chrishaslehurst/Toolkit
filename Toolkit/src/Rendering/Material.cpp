#include "Material.h"
#include "Shader.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace tk
{
    void Material::Compile(const MaterialDef &definition) 
    {
        // #todo-ch 25/06/2022: Improve this by having a shader cache somewhere - otherwise shaders may be loaded and compiled many times
        // Vertex Shader
        Shader vertexShader(definition.vertexShaderPath.c_str(), ShaderType::Vertex);
        // Fragment Shader
        Shader fragmentShader(definition.fragmentShaderPath.c_str(), ShaderType::Fragment);

        int success;
        char infoLog[512];

        // Create Shader Program
        shaderProgramIndex = glCreateProgram();
        glAttachShader(shaderProgramIndex, vertexShader.getIndex());
        glAttachShader(shaderProgramIndex, fragmentShader.getIndex());
        glLinkProgram(shaderProgramIndex);

        glGetProgramiv(shaderProgramIndex, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgramIndex, 512, nullptr, infoLog);
            TK_CORE_ERROR("Shader program link failed:\n {}", infoLog);
            shaderProgramIndex = -1;
        }

        tex.Generate(definition.texturePath.c_str());
    }

    void Material::Use() 
    { 
        glUseProgram(shaderProgramIndex);
        glBindTexture(GL_TEXTURE_2D, tex.GetIndex());
    }

} // namespace toolkit
