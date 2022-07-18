#include "GLCallbacks.h"
#include "Log.h"
#include "GLFW/glfw3.h"
#include "Application.h"

namespace toolkit
{

	void errorCallback(s32 error, const char* description)
	{
		TK_CORE_ERROR("GLFW error {}: {}", error, description);
	}

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Application* system = static_cast<toolkit::Application*>(glfwGetWindowUserPointer(window));
		if (system)
		{
			system->ReceiveInput(window, key, scancode, action, mods);
		}
	}

}