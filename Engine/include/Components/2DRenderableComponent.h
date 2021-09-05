#pragma once
#include <memory>

namespace render
{
	class Shape2D;
}

class Renderable2DComponent
{
public:
	Renderable2DComponent();
	~Renderable2DComponent();

	void SetShape();
	void Draw();

private:
	std::unique_ptr<render::Shape2D> Renderable;
};
