#include "Rendering/Window.h"
#include "GLCallbacks.h"
#include "glad/glad.h"

#include "GLFW/glfw3.h"

namespace tk
{
    Window::Window(u32 width, u32 height, const char *windowName, void *system)
    {
        glfwInit();
        
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwSetErrorCallback(tk::errorCallback);

        window = glfwCreateWindow(width, height, windowName, nullptr, nullptr);
        if (!window)
        {
            TK_CORE_ERROR("Failed to create GLFW window");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            TK_CORE_ERROR("Failed to initialize GLAD");
            return;
        }

        glViewport(0, 0, width, height);
        glClearColor(0.15f, 0.6f, 0.4f, 1.0f);
        glfwSetWindowUserPointer(window, system);
        glfwSetKeyCallback(window, tk::keyCallback);
        glfwSetFramebufferSizeCallback(window, tk::FrameBufferSizeCallback);

        
    }

    void Window::PreRenderUpdate() 
    { 
        glClear(GL_COLOR_BUFFER_BIT);
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Wireframe
    }

    bool Window::Update()
    {
        if (!glfwWindowShouldClose(window))
        {
            glfwPollEvents();
            glfwSwapBuffers(window);

            return true;
        }
        else
        {
            glfwDestroyWindow(window);
            glfwTerminate();
            return false;
        }
    }

    void FrameBufferSizeCallback(GLFWwindow *window, s32 width, s32 height) { glViewport(0, 0, width, height); }

} // namespace toolkit