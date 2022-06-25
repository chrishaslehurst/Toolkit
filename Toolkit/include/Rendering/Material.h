#pragma once
#include "CoreMinimal.h"

namespace toolkit
{
	struct MaterialDef
	{
		std::string vertexShaderPath;
		std::string fragmentShaderPath;
	};

	class Material
	{
	public:
		void Compile(const MaterialDef& definition);
		void Use();
	private:
		u32 shaderProgramIndex = 0;
	};
}