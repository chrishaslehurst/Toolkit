#pragma once

#include <memory>

namespace render {
	enum class ERenderingAPI : uint8_t;
	class Window;
}
class Input;

class Game
{

public:
	Game();
	~Game();

	bool Update();
	void HandleInput();

private:
	std::unique_ptr<render::Window> window;
	std::unique_ptr<Input> input;
	render::ERenderingAPI api;
};
