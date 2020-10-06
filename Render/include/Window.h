#pragma once
#include <stdint.h>
#include "Renderables/Shape2D.h"

struct GLFWwindow;

namespace render
{
	
	class SWindow
	{
	public:

		bool Create(int32_t width, int32_t height);
		bool Update();

		GLFWwindow* GetGLWindow() const {return glWindow;};
	private:
		GLFWwindow* glWindow;
	};

	void FrameBufferSizeCallback(GLFWwindow* window, int32_t width, int32_t height);

}