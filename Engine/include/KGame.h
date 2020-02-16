#pragma once

#include <memory>
namespace kraken {
    
    namespace render
    {
        class KWindow;
    }

    class KGame
    {

    public:

        KGame();
        ~KGame();
        
        bool Update();
        void HandleInput();


    private:
        std::unique_ptr<render::KWindow> window;

    };
}