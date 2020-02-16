#include "Game.h"
#include "Window.h"
#include <iostream>
#include <GLFW/glfw3.h>

Game::Game()
{
	window = std::make_unique<Render::Window>();
}

Game::~Game()
{

}

void Game::Run()
{
	window->Create(800, 600);
	while (window->Update())
	{
		HandleInput();
	}
}

void Game::HandleInput()
{
	if (glfwGetKey(window->GetGLWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window->GetGLWindow(), true);
	}
}