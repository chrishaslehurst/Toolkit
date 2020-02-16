#include "KGame.h"
#include "KWindow.h"
#include <iostream>
#include <GLFW/glfw3.h>
namespace kraken {
	
	KGame::KGame()
	{
		window = std::make_unique<render::KWindow>();
		window->Create(800, 600);
	}

	KGame::~KGame()
	{

	}

	bool KGame::Update()
	{
		
		if (window->Update())
		{
			HandleInput();
			return true;
		}
		return false;
	}

	void KGame::HandleInput()
	{
		if (glfwGetKey(window->GetGLWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window->GetGLWindow(), true);
		}
	}
}