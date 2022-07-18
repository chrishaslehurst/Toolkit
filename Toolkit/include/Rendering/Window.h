#pragma once
#include "CoreMinimal.h"

struct GLFWwindow;

namespace toolkit {

	class Window 
	{
		friend class Application;
	public:
		Window(u32 width, u32 height, const char* windowName, void* system);
		void PreRenderUpdate();
		bool Update();
	private:
		
		GLFWwindow* window = nullptr;
	};

	void FrameBufferSizeCallback(GLFWwindow* window, s32 width, s32 height);
	
}  // namespace render