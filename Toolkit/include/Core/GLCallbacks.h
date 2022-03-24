#pragma once

#include "CoreMinimal.h"

struct GLFWwindow;

namespace toolkit
{
	void errorCallback(s32 error, const char* description);

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
}