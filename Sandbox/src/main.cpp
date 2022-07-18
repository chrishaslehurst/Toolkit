#include <stdio.h>
#include "Application.h"
#include "imgui.h"
#include "Mesh.h"
#include "Material.h"

void UpPressed() { TK_CORE_INFO("Up Pressed"); }

class SandboxApp : public toolkit::Application
{
public:
	
	void VoidTestCallback()
	{
		TK_CORE_INFO("Void Test");
	}

	void TestCallback(s32 test, s32 test2)
	{
		TK_CORE_INFO("Member with Vars Test: {} {}", test, test2);
	}

protected:
	void OnStartup() override
	{
		AddScene(800, 600, "Sandbox");

		square.Setup();

		toolkit::MaterialDef def;
		def.vertexShaderPath = "content/shaders/vertex.glsl";
		def.fragmentShaderPath = "content/shaders/fragment.glsl";
		mat.Compile(def);
		
		GetInput()->BindKey<&SandboxApp::VoidTestCallback>(GLFW_KEY_T, GLFW_PRESS, GLFW_MOD_SHIFT, this);
		GetInput()->BindKey<&UpPressed>(GLFW_KEY_UP, GLFW_PRESS, 0);
	}
	void OnUpdate() override
	{
		mat.Use();
		square.Draw();

		ImGui::ShowDemoWindow(&showDemoWindow);
	}
	void OnShutdown() override
	{

	}
private:

	toolkit::Mesh square;
	toolkit::Material mat;

	bool showDemoWindow = true;
};

int main() {

	SandboxApp app;
	app.Run();

	return 0;
}