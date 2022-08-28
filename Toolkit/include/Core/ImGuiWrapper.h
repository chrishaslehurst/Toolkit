#pragma once

struct GLFWwindow;

namespace tk {

	class ImGuiWrapper
	{
	public:
		void Setup(GLFWwindow* window);
		void StartFrame();
		void EndFrame();
		void Shutdown();
	};
}