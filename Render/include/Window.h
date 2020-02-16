#pragma once
#include <stdint.h>

struct GLFWwindow;

namespace Render
{
	class Shape2D
	{
	public:
		void SetShaderHandle(uint32_t inShaderHandle)
		{
			shaderHandle = inShaderHandle;
		}

		void SetVAOHandle(uint32_t inVAOHandle)
		{
			vaoHandle = inVAOHandle;
		}

		void Draw();

	private:
		

		uint32_t shaderHandle;
		uint32_t vaoHandle;
	};

	class Window
	{
	public:

		bool Create(int32_t width, int32_t height);
		bool Update();

		void SetupShape(Shape2D& Shape);

		GLFWwindow* GetGLWindow() const {return glWindow;};
	private:
		Shape2D tri;
		GLFWwindow* glWindow;
	};

	void FrameBufferSizeCallback(GLFWwindow* window, int32_t width, int32_t height);
}