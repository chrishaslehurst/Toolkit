#include "Renderables/Shape2D.h"
#include "glad/glad.h"
#include <string>
#include "Utils.h"
#include <iostream>

namespace render {

	void Shape2D::Setup()
	{
		// #todo-2020/01/27:  factor out loading shaders at LEAST into functions..
			//compile vertex shader
		u32 vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		std::string vertexShaderSource = Utilities::LoadFile("../content/shaders/vertex.glsl").data();
		const char* vertShaderPtr = vertexShaderSource.c_str();
		glShaderSource(vertexShader, 1, &vertShaderPtr, NULL);
		glCompileShader(vertexShader);

		int  shaderCompileSuccess;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &shaderCompileSuccess);
		if (!shaderCompileSuccess)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "Error: Vertex Shader Compilation Failed: \n" << infoLog << std::endl;
		}

		//compile fragment shader
		u32 fragShader;
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);

		std::string fragShaderSource = Utilities::LoadFile("../content/shaders/fragment.glsl").data();
		const char* fragShaderPtr = fragShaderSource.c_str();
		glShaderSource(fragShader, 1, &fragShaderPtr, NULL);
		glCompileShader(fragShader);

		glGetShaderiv(fragShader, GL_COMPILE_STATUS, &shaderCompileSuccess);
		if (!shaderCompileSuccess)
		{
			glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
			std::cout << "Error: Fragment Shader Compilation Failed: \n" << infoLog << std::endl;
		}

		u32 shaderProgram;
		shaderProgram = glCreateProgram();

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragShader);
		glLinkProgram(shaderProgram);

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shaderCompileSuccess);
		if (!shaderCompileSuccess)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragShader);

		SetShaderHandle(shaderProgram);

		//Vertex Buffers
		u32 VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		u32 VBO;
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		float vertices[9] =
		{
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(f32), (void*)0);
		glEnableVertexAttribArray(0);
		SetVAOHandle(VAO);
	}

	void Shape2D::SetShaderHandle(u32 inShaderHandle)
	{
		shaderHandle = inShaderHandle;
	}

	void Shape2D::SetVAOHandle(u32 inVAOHandle)
	{
		vaoHandle = inVAOHandle;
	}

	void Shape2D::Draw()
	{
		glUseProgram(shaderHandle);
		glBindVertexArray(vaoHandle);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}