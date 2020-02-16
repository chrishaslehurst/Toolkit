#include "Components/K2DRenderableComponent.h"
#include <Renderables/KShape2D.h>

namespace kraken
{

	K2DRenderableComponent::K2DRenderableComponent()
	{
		Renderable = std::make_unique<render::KShape2D>();
	}

	K2DRenderableComponent::~K2DRenderableComponent()
	{

	}

	void K2DRenderableComponent::SetShape()
	{
		Renderable->Setup();
	}

	void K2DRenderableComponent::Draw()
	{
		Renderable->Draw();
	}
}

