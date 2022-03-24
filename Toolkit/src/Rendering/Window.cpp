#include "Rendering/Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "GLCallbacks.h"

namespace toolkit
{
	Window::Window(u32 width, u32 height, const char* windowName, void* system)
	{
		Create(width, height, windowName, system);
	}

	bool Window::Create(u32 width, u32 height, const char* windowName, void* system)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwSetErrorCallback(toolkit::errorCallback);

		window = glfwCreateWindow(width, height, windowName, nullptr, nullptr);
		if (!window)
		{
			TK_CORE_ERROR("Failed to create GLFW window");
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			TK_CORE_ERROR("Failed to initialize GLAD");
			return false;
		}

		glViewport(0, 0, width, height);
		glClearColor(0.15f, 0.6f, 0.4f, 1.0f);
		glfwSetWindowUserPointer(window, system);
		glfwSetKeyCallback(window, toolkit::keyCallback);
		glfwSetFramebufferSizeCallback(window, toolkit::FrameBufferSizeCallback);

		return true;
	}

	bool Window::Update()
	{
		if (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window);
			glfwPollEvents();
			return true;
		}
		else
		{
			glfwDestroyWindow(window);
			glfwTerminate();
			return false;
		}
	}

	void FrameBufferSizeCallback(GLFWwindow* window, s32 width, s32 height)
	{
		glViewport(0, 0, width, height);
	}

} // namespace render