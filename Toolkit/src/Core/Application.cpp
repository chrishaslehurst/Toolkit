#include "Application.h"

namespace toolkit
{
    

    Application::Application()
    {
        Log::Init();
        input = std::make_unique<Input>();
    }

    void Application::AddScene(u32 width, u32 height, const char *windowName)
    {
        window = std::make_unique<Window>(width, height, windowName, this);
        imgui = std::make_unique<ImGuiWrapper>();
        imgui->Setup(window->window);
    }

    void Application::Run()
    {
        bool Running = true;
        TK_CORE_INFO("Log Begin");
        
        OnStartup();
        while (Running)
        {
            Running = Update();
        }
    }

    bool Application::Update()
    {
        if (nullptr != window)
        {
            window->PreRenderUpdate();
        }
       
        if (nullptr != imgui)
        {
            imgui->StartFrame();
        }
            
        OnUpdate();
            
        if (nullptr != imgui)
        {
            imgui->EndFrame();
        }
        
        if (nullptr != window && window->Update())
        {
            return true;
        }
        else
        {
            if (nullptr != imgui)
            {
                imgui->Shutdown();
            }
            OnShutdown();
            return false;
        }
    }

    void Application::ReceiveInput(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        input->ReceiveInput(window, key, action, mods);
    }

} // namespace toolkit