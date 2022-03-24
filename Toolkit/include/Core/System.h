#pragma once

#include "CoreMinimal.h"
#include <memory>
#include "Input.h"
#include "Window.h"

namespace toolkit {

	class System
	{
	public:
		System();
		void AddScene(u32 width, u32 height, const char* windowName);
		void Run();
		bool Update();
		void ReceiveInput(GLFWwindow* window, int key, int scancode, int action, int mods);
	private:
		std::unique_ptr<Window> window;
		std::unique_ptr<Input> input;
	};
}
