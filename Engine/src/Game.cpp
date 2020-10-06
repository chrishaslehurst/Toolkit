#include "Game.h"
#include "Window.h"
#include <iostream>

	
SGame::SGame()
{
	// #todo-2020/10/06: replace this with an abstract factory? want render mode set once somewhere and thats IT (GL/DX/Vulkan)
	window = render::CreateWindow(800, 600);
}

SGame::~SGame()
{

}

bool SGame::Update()
{
	if (window->Update())
	{
		HandleInput();
		return true;
	}
	return false;
}

void SGame::HandleInput()
{
	// #todo-2020/10/06: refactor input management..
// 	if (glfwGetKey(window->GetGLWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
// 	{
// 		glfwSetWindowShouldClose(window->GetGLWindow(), true);
// 	}
}
