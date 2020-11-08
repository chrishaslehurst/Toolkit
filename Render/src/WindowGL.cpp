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
        void errorCallback(int32_t error, const char *description)
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

        SWindowGL::SWindowGL(uint32_t width, uint32_t height)
        {
            Create(width, height);
        }

        bool SWindowGL::Create(uint32_t width, uint32_t height)
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

            glfwSetKeyCallback(glWindow, keyCallback);
            glfwMakeContextCurrent(glWindow);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cout << "Failed to initialize GLAD" << std::endl;
                return false;
            }

            glViewport(0, 0, width, height);
            glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

            glfwSetKeyCallback(glWindow, render::gl::KeyCallback);
            glfwSetFramebufferSizeCallback(glWindow, render::gl::FrameBufferSizeCallback);

            return true;
        }

        bool SWindowGL::Update()
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

        void FrameBufferSizeCallback(GLFWwindow *window, int32_t width, int32_t height)
        {
            glViewport(0, 0, width, height);
        }
    } // namespace gl
} // namespace render