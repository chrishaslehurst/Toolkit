#include "Window.h"
#include "WindowGL.h"
#include <cassert>

namespace render
{
    std::unique_ptr<Window> CreateWindow(u32 width, u32 height, ERenderingAPI backend)
    {
        switch (backend)
        {
        case ERenderingAPI::OpenGL:
            return std::make_unique<render::gl::WindowGL>(width, height);
        case ERenderingAPI::DirectX11:
        case ERenderingAPI::Vulkan:
        default:
            assert(false);
            return nullptr;
        }
        return nullptr;
    }
} // namespace render