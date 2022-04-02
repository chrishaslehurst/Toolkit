#include <stdio.h>
#include "System.h"

int main() {

	toolkit::System system;
	system.AddScene(800, 600, "Sandbox");
	system.Run();

	return 0;
}