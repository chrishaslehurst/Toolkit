#include "Components/2DRenderableComponent.h"
#include <Renderables/Shape2D.h>

Renderable2DComponent::Renderable2DComponent()
{
	Renderable = std::make_unique<render::Shape2D>();
}

Renderable2DComponent::~Renderable2DComponent()
{
}

void Renderable2DComponent::SetShape()
{
	Renderable->Setup();
}

void Renderable2DComponent::Draw()
{
	Renderable->Draw();
}
