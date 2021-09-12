#include <stdio.h>
#include "Components/2DRenderableComponent.h"
#include "Game.h"

int main() {
  bool Running = true;


  Game game;
  // #ktodo-2020/02/16: need to acquire a ptr to this via the game object so
  // game can deal with updating/drawing
  Renderable2DComponent Tri;

  Tri.SetShape();

  while (Running) {
    Running = game.Update();

    // Do all the things.
    Tri.Draw();
  }

  return 0;
}