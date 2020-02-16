#pragma once

#include <memory>

namespace Render
{
    class Window;
}

class Game
{
    
public:
    Game();
    ~Game();
    void Run();
    void HandleInput();


private:
    std::unique_ptr<Render::Window> window;

};
