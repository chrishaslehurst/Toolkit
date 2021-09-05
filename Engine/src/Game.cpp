#include "Game.h"
#include "Window.h"
#include "Input.h"
#include <iostream>

Game::Game()
{
	api = render::ERenderingAPI::OpenGL;
	window = render::CreateWindow(800, 600, api);
	input = std::make_unique<InputGL>();
	//todo: subscribe the callback to the window from the input here...
}

Game::~Game()
{
}

bool Game::Update()
{
	if (window->Update())
	{
		input->ReceiveInput(0, 0, 0);
		HandleInput();
		return true;
	}
	return false;
}

void Game::HandleInput()
{
	
}
