#pragma once

#include "CoreMinimal.h"

struct GLFWwindow;

namespace tk
{
	void errorCallback(s32 error, const char* description);

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
}