#pragma once
#include <stdint.h>

namespace render {

	class SShape2D
	{
	public:
		void Setup();

		void SetShaderHandle(uint32_t inShaderHandle);
		void SetVAOHandle(uint32_t inVAOHandle);
		void Draw();

	private:

		uint32_t shaderHandle;
		uint32_t vaoHandle;
	};
}