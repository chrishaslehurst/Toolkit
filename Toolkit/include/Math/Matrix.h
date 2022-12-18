#pragma once
#include "CoreMinimal.h"

namespace tk
{
	class Transform
	{
		Transform(f32 inMembers[4][4])
		{
			memcpy(members, inMembers, sizeof(f32) * 16);
		}
		static const Transform identity;


	private:
		f32 members[4][4];
	};


	const Transform Transform::identity{1.f, 0.f, 0.f, 0.f,
										0.f, 1.f, 0.f, 0.f,
										0.f, 0.f, 1.f, 0.f,
										0.f, 0.f, 0.f, 1.f };

}