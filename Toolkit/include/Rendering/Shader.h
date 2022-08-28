#pragma once
#include "CoreMinimal.h"

namespace tk {
	enum class ShaderType
	{
		Vertex,
		Fragment,
		Geometry,
		Compute
	};

	class Shader 
	{

	public:
		Shader(const char* filepath, ShaderType type);
		~Shader();
		u32 getIndex() const { return shaderIndex; };
	private:
		u32 shaderIndex = 0;
	};
}