#pragma once

#include "CoreMinimal.h"

namespace toolkit
{
	class Texture
	{
	public:
		void Generate(const char* file);
		u32 GetIndex();
	private:
		u32 index = 0;
	};
}