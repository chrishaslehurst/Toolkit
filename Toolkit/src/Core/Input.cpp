#include "Input.h"
#include <GLFW/glfw3.h>

namespace toolkit
{
	void Input::ReceiveInput(GLFWwindow* window, s32 key, s32 action, s32 mods)
	{
		//GLFW_MOD_SHIFT
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}

		for (const KeyBind& bind : keyBinds)
		{
			if (bind.key == key && bind.action == action && bind.mods == mods)
			{
				bind.binding.Invoke();
			}
		}

// 		Delegate<> Callback = Delegate<>::FromMemberFunction<Input, &Input::VoidTestCallback>(this);
// 		Callback.Invoke();
// 
// 		Delegate<s32, s32> Callback2 = Delegate<s32, s32>::FromMemberFunction<Input, &Input::TestCallback>(this);
// 		Callback2.Invoke(1, 2);
// 
// 		Delegate<s32, s32> Callback3 = Delegate<s32, s32>::FromFreeFunction<&FreeFuncCallbackTest>();
// 		Callback3.Invoke(5, 6);
	}

	void Input::VoidTestCallback()
	{
		TK_CORE_INFO("Void Test");
	}

	void Input::TestCallback(s32 test, s32 test2)
	{
		TK_CORE_INFO("Member with Vars Test: {} {}", test, test2);
	}

	void FreeFuncCallbackTest(s32 test1, s32 test2)
	{
		TK_CORE_INFO("Free Function Test: {} {}", test1, test2);
	}
}
