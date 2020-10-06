#include "Window.h"

struct GLFWwindow;
namespace render
{
	namespace gl
	{
		class SWindowGL : public SWindow
		{
		public:
			SWindowGL(uint32_t width, uint32_t height);

			bool Create(uint32_t width, uint32_t height) override;
			bool Update() override;

		private:
			GLFWwindow *glWindow;
		};

		void FrameBufferSizeCallback(GLFWwindow *window, int32_t width, int32_t height);
	} // namespace gl
} // namespace render