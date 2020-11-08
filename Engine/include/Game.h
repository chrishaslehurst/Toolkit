#pragma once

#include <memory>

namespace render
{
	class SWindow;
}
class SInput;

class SGame
{

public:
	SGame();
	~SGame();

	bool Update();
	void HandleInput();

private:
	std::unique_ptr<render::SWindow> window;
	std::unique_ptr<SInput> input;
};
