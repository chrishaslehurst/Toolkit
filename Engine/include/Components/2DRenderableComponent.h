#pragma once
#include <memory>

namespace render
{
	class SShape2D;
}

class S2DRenderableComponent
{
public:
	S2DRenderableComponent();
	~S2DRenderableComponent();

	void SetShape();
	void Draw();

private:
	std::unique_ptr<render::SShape2D> Renderable;
};
