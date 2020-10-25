#pragma once
#include <stdint.h>
#include <memory>

namespace render {
enum class RenderBackend : uint8_t { OpenGL, Vulkan, DirectX11, Max };

class SWindow {
 public:
  virtual ~SWindow(){};

  virtual bool Create(uint32_t width, uint32_t height) = 0;
  virtual bool Update() = 0;
};

std::unique_ptr<SWindow> CreateWindow(uint32_t width, uint32_t height);
}  // namespace render