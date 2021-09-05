#include "Window.h"
#include "CoreMinimal.h"

struct GLFWwindow;
namespace render
{
	namespace gl
	{
		class WindowGL : public Window
		{
		public:
			WindowGL(u32 width, u32 height);

			bool Create(u32 width, u32 height) override;
			bool Update() override;

		private:
			GLFWwindow *glWindow;
		};

		void FrameBufferSizeCallback(GLFWwindow *window, s32 width, s32 height);
	} // namespace gl
} // namespace render