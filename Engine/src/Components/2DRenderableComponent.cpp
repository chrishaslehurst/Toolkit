#include "Components/2DRenderableComponent.h"
#include <Renderables/Shape2D.h>

S2DRenderableComponent::S2DRenderableComponent()
{
	Renderable = std::make_unique<render::SShape2D>();
}

S2DRenderableComponent::~S2DRenderableComponent()
{
}

void S2DRenderableComponent::SetShape()
{
	Renderable->Setup();
}

void S2DRenderableComponent::Draw()
{
	Renderable->Draw();
}
