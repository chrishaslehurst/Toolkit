#pragma once
#include <stdint.h>
#include <memory>
#include "CoreMinimal.h"

namespace render {

	enum class ERenderingAPI : u8
	{
		OpenGL,
		Vulkan,
		DirectX11
	};

	class Window {
	public:
		virtual ~Window() {};

		virtual bool Create(u32 width, u32 height) = 0;
		virtual bool Update() = 0;
	};

	std::unique_ptr<Window> CreateWindow(u32 width, u32 height, ERenderingAPI platform);
}  // namespace render