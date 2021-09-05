#include "Input.h"
#include <GLFW/glfw3.h>

#include <iostream>


InputGL::InputGL()
{
    AddKeyToMap(GLFW_KEY_SPACE, Key::SPACE);
    AddKeyToMap(GLFW_KEY_A, Key::A);
    AddKeyToMap(GLFW_KEY_B, Key::B);
    AddKeyToMap(GLFW_KEY_C, Key::C);
    AddKeyToMap(GLFW_KEY_D, Key::D);
    AddKeyToMap(GLFW_KEY_E, Key::E);
	AddKeyToMap(GLFW_KEY_F, Key::F);
	AddKeyToMap(GLFW_KEY_G, Key::G);
	AddKeyToMap(GLFW_KEY_H, Key::H);
	AddKeyToMap(GLFW_KEY_I, Key::I);
	AddKeyToMap(GLFW_KEY_J, Key::J);
	AddKeyToMap(GLFW_KEY_K, Key::K);
	AddKeyToMap(GLFW_KEY_L, Key::L);
	AddKeyToMap(GLFW_KEY_M, Key::M);
	AddKeyToMap(GLFW_KEY_N, Key::N);
	AddKeyToMap(GLFW_KEY_O, Key::O);
}

void InputGL::ReceiveInput(s32 key, s32 action, s32 mods)
{
    Delegate<> Callback = Delegate<>::FromMemberFunction<InputGL, &InputGL::VoidTestCallback>(this);
    Callback.Invoke();

	Delegate<s32, s32> Callback2 = Delegate<s32, s32>::FromMemberFunction<InputGL, &InputGL::TestCallback>(this);
 	Callback2.Invoke(1,2);

	Delegate<s32, s32> Callback3 = Delegate<s32, s32>::FromFreeFunction<&FreeFuncCallbackTest>();
	Callback3.Invoke(5, 6);
}

void InputGL::VoidTestCallback()
{
    std::cout << "Void Test";
}

void InputGL::TestCallback(s32 test, s32 test2)
{
    std::cout << "Member with Vars Test: " << test << " " << test2;
}

void InputGL::AddKeyToMap(s32 glKey, Key engineKey)
{
	KeyCodes.push_back(glKey);
	Keys.push_back(engineKey);
	KeyStates.push_back(KeyState());
}

void FreeFuncCallbackTest(s32 test1, s32 test2)
{
    std::cout << "Free Func Test: " << test1 << " " << test2;
}
