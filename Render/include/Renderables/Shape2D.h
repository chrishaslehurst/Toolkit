#pragma once
#include "CoreMinimal.h"

namespace render {

	class Shape2D
	{
	public:
		void Setup();

		void SetShaderHandle(u32 inShaderHandle);
		void SetVAOHandle(u32 inVAOHandle);
		void Draw();

	private:

		u32 shaderHandle;
		u32 vaoHandle;
	};
}