#pragma once
#include "CoreMinimal.h"
#include "Texture.h"

namespace toolkit
{
	struct MaterialDef
	{
		std::string vertexShaderPath;
		std::string fragmentShaderPath;
		std::string texturePath;
	};

	class Material
	{
	public:
		void Compile(const MaterialDef& definition);
		void Use();
	private:
		u32 shaderProgramIndex = 0;
		Texture tex;
	};
}