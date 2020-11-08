#include "Input.h"
#include <GLFW/glfw3.h>

 //void SInput::BindKey(SEKeyCode key, std::function callback)
 //{
    // KeyBindings[key] = callback;
 //}

SInputGL::SInputGL()
{
    //todo: initialise the key translation map
    glfwToSEKey[GLFW_KEY_UNKNOWN]   = SEKeyCode::UNKNOWN;
    glfwToSEKey[GLFW_KEY_SPACE]     = SEKeyCode::SPACE;
}

void SInputGL::ReceiveInput(int key, int action, int mods)
{
    glfwToSEKey.find(key)
}