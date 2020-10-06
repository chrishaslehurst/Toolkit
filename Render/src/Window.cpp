#include "Window.h"

#include <cassert>
#include "WindowGL.h"

namespace render
{
    std::unique_ptr<SWindow> CreateWindow(uint32_t width, uint32_t height)
    {
        RenderBackend backend = RenderBackend::OpenGL;
        switch(backend)
        {
            case RenderBackend::OpenGL:
                return std::make_unique<render::gl::SWindowGL>(width, height);
            case RenderBackend::DirectX11:
            case RenderBackend::Vulkan:
            case RenderBackend::Max:
                assert(false);
                return nullptr;
        }
        return nullptr;
    }
}