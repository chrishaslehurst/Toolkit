#pragma once

#include "CoreMinimal.h"
#include <memory>

#include "ImGuiWrapper.h"
#include "Input.h"
#include "Window.h"
#include "GLFW/glfw3.h"

struct GLFWwindow;

namespace tk {
	
	class Application
	{
	public:
		Application();
		void Run();
		void ReceiveInput(GLFWwindow* window, int key, int scancode, int action, int mods);
		Input* GetInput() { return input.get(); }
	protected:
		virtual void OnStartup() = 0;
		virtual void OnUpdate(float deltaSeconds) = 0;
		virtual void OnShutdown() = 0;

		void AddScene(u32 width, u32 height, const char* windowName);
	private:
		bool Update();
		std::unique_ptr<Window> window = nullptr;
		std::unique_ptr<Input> input = nullptr;
		std::unique_ptr<ImGuiWrapper> imgui = nullptr;

		double lastFrameTime = 0;
	};
}
