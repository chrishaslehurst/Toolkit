#include "WindowGL.h"
#include "Utils.h"
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <iostream>
#include <stdio.h>

namespace render
{
    namespace gl
    {
        void errorCallback(s32 error, const char *description)
        {
            fprintf(stderr, "GLFW error %d: %s\n", error, description);
        }

		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	        {
	        	glfwSetWindowShouldClose(window, true);
	        }
		}

        WindowGL::WindowGL(u32 width, u32 height)
        {
            Create(width, height);
        }

        bool WindowGL::Create(u32 width, u32 height)
        {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            glfwSetErrorCallback(errorCallback);

            glWindow = glfwCreateWindow(width, height, "UnnamedEngineWindow", nullptr, nullptr);
            if (!glWindow)
            {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return false;
            }

            glfwMakeContextCurrent(glWindow);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cout << "Failed to initialize GLAD" << std::endl;
                return false;
            }

            glViewport(0, 0, width, height);
            glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

            glfwSetKeyCallback(glWindow, render::gl::keyCallback);
            glfwSetFramebufferSizeCallback(glWindow, render::gl::FrameBufferSizeCallback);

            return true;
        }

        bool WindowGL::Update()
        {
            if (!glfwWindowShouldClose(glWindow))
            {
                glClear(GL_COLOR_BUFFER_BIT);

                glfwSwapBuffers(glWindow);
                glfwPollEvents();
                return true;
            }
            else
            {
                glfwDestroyWindow(glWindow);
                glfwTerminate();
                return false;
            }
        }

        void FrameBufferSizeCallback(GLFWwindow *window, u32 width, u32 height)
        {
            glViewport(0, 0, width, height);
        }
    } // namespace gl
} // namespace render