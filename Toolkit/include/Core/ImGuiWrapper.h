#pragma once

struct GLFWwindow;

namespace toolkit {

	class ImGuiWrapper
	{
	public:
		void Setup(GLFWwindow* window);
		void StartFrame();
		void EndFrame();
		void Shutdown();
	};
}