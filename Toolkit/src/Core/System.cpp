#include "System.h"
#include "Input.h"
#include "GLFW/glfw3.h"

namespace toolkit
{
	void UpPressed()
	{
		TK_CORE_INFO("Up Pressed");
	}

	System::System()
	{
		input = std::make_unique<toolkit::Input>();
		input->BindKey<toolkit::Input, &toolkit::Input::VoidTestCallback>(GLFW_KEY_T, GLFW_PRESS, GLFW_MOD_SHIFT, input.get());
		input->BindKey<&toolkit::UpPressed>(GLFW_KEY_UP, GLFW_PRESS, 0);
	}

	void System::AddScene(u32 width, u32 height, const char* windowName)
	{
		window = std::make_unique<toolkit::Window>(width, height, windowName, this);
	}

	void System::Run()
	{
		bool Running = true;

		toolkit::Log::Init();
		TK_CORE_INFO("Log Begin");

		while (Running) {
			Running = Update();
		}
	}

	bool System::Update()
	{
		if (window != nullptr && window->Update())
		{
			return true;
		}
		return false;
	}

	void System::ReceiveInput(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		input->ReceiveInput(window, key, action, mods);
	}

}