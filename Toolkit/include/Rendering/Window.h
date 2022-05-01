#pragma once
#include "CoreMinimal.h"
#include "Defines.h"

struct GLFWwindow;

namespace toolkit {

	class Window 
	{
	
	public:
		Window(u32 width, u32 height, const char* windowName, void* system);
		bool Update();
	private:

		u32 shaderProgram;
		u32 vertexArrayObject;
		u32 elementBufferObject;
		GLFWwindow* window = nullptr;
	};

	void FrameBufferSizeCallback(GLFWwindow* window, s32 width, s32 height);
	
}  // namespace render