#pragma once

#include "CoreMinimal.h"

namespace toolkit {

	class Material;

	class Mesh
	{
		struct Vertex {
			//vec3 position
			//vec3 normal
			//vec2 uv
		};

	public:
		Mesh();
		void Setup();
		void Draw();
	private:

		u32 vertexArrayObject;
		u32 elementBufferObject;
		Material* Mat;
	};

}