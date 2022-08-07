#include <stdio.h>
#include "Application.h"
#include "imgui.h"
#include "Mesh.h"
#include "Material.h"

void UpPressed() { TK_CORE_INFO("Up Pressed"); }

class SandboxApp : public toolkit::Application
{
public:
	
	void ToggleMenu()
	{
		showMenu = !showMenu;
	}

	void TestCallback(s32 test, s32 test2)
	{
		TK_CORE_INFO("Member with Vars Test: {} {}", test, test2);
	}

protected:
	void OnStartup() override
	{
		AddScene(1200, 900, "Sandbox");

		square.Setup();

		toolkit::MaterialDef def;
		def.vertexShaderPath = "content/shaders/vertex.glsl";
		def.fragmentShaderPath = "content/shaders/fragment.glsl";
		def.texturePath = "content/textures/scout.jpg";
		mat.Compile(def);
		
		GetInput()->BindKey<&SandboxApp::ToggleMenu>(GLFW_KEY_D, GLFW_PRESS, GLFW_MOD_CONTROL, this);
		GetInput()->BindKey<&UpPressed>(GLFW_KEY_UP, GLFW_PRESS, 0);
	}
	void OnUpdate(float deltaSeconds) override
	{
		mat.Use();
		square.Draw();

		if (showMenu)
		{
			DrawMenu(deltaSeconds);
		}
	}
	void OnShutdown() override
	{

	}
private:

	void DrawMenu(float deltaSeconds)
	{
		// Create a window called "My First Tool", with a menu bar.
		ImGui::Begin("Sandbox Menu", &showMenu, ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Text("Frame Time : %.2f (ms)", deltaSeconds * 1000);
		ImGui::End();
	}

	toolkit::Mesh square;
	toolkit::Material mat;

	bool showMenu = false;
};

int main() {

	SandboxApp app;
	app.Run();

	return 0;
}