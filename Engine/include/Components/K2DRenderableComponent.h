#pragma once
#include <memory>

namespace kraken
{
	namespace render
	{
		class KShape2D;
	}

	class K2DRenderableComponent 
	{
	public:
		K2DRenderableComponent();
		~K2DRenderableComponent();

		void SetShape();
		void Draw();
	private:
		std::unique_ptr<render::KShape2D> Renderable;
	};
}