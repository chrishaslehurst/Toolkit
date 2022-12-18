#pragma once

#include "CoreMinimal.h"

namespace tk
{
	struct Vector3
	{
		constexpr Vector3() = default;
		constexpr Vector3(f32 inX, f32 inY, f32 inZ)
			: X(inX), Y(inY), Z(inZ)
		{}

		f32 X = 0.f;
		f32 Y = 0.f;
		f32 Z = 0.f;
	};

	
	constexpr Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
	{
		Vector3 res;
		res.X = lhs.X + rhs.X;
		res.Y = lhs.Y + rhs.Y;
		res.Z = lhs.Z + rhs.Z;
		
		return res;
	}

	constexpr Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
	{
		Vector3 res;
		res.X = lhs.X - rhs.X;
		res.Y = lhs.Y - rhs.Y;
		res.Z = lhs.Z - rhs.Z;
		return res;
	}

	constexpr bool operator==(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;		
	}

	namespace vector
	{
		[[nodiscard]] constexpr float DotProduct(const Vector3& lhs, const Vector3& rhs);
		[[nodiscard]] constexpr Vector3 CrossProduct(const Vector3& lhs, const Vector3& rhs);
		[[nodiscard]] constexpr float DistSquared(const Vector3& a, const Vector3& b);
		[[nodiscard]] float Dist(const Vector3& a, const Vector3& b);
		[[nodiscard]] constexpr float LengthSquared(const Vector3& vec);
		[[nodiscard]] float Length(const Vector3& vec);
	}
}