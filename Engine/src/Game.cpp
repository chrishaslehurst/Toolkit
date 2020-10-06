#include "Game.h"
#include "Window.h"
#include <iostream>
#include <GLFW/glfw3.h>

	
SGame::SGame()
{
	window = std::make_unique<render::SWindow>();
	window->Create(800, 600);
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
	if (glfwGetKey(window->GetGLWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window->GetGLWindow(), true);
	}
}
