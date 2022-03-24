#pragma once
#include "CoreMinimal.h"
#include "Defines.h"

struct GLFWwindow;

namespace toolkit {

	class Window 
	{
	
	public:
		Window(u32 width, u32 height, const char* windowName, void* system);

		bool Create(u32 width, u32 height, const char* windowName, void* system);
		bool Update();
	private:
		GLFWwindow* window = nullptr;
	};

	void FrameBufferSizeCallback(GLFWwindow* window, s32 width, s32 height);
	
}  // namespace render