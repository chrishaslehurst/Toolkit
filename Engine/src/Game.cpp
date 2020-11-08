#include "Game.h"
#include "Window.h"
#include "Input.h"
#include <iostream>

SGame::SGame()
{
	// #todo-2020/10/06: replace this with an abstract factory? want render mode set once somewhere and thats IT (GL/DX/Vulkan)
	window = render::CreateWindow(800, 600);
	//and factor the creation of this into similar functionality - set gl once, have that decide what to create.
	input = std::make_unique<SInputGL>();
	//todo: subscribe the callback to the window from the input here...
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
	
}
