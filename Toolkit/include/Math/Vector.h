#pragma once

#include "CoreMinimal.h"

namespace toolkit
{
	namespace math
	{
		struct Vector2
		{
			f32 X = 0.f;
			f32 Y = 0.f;
		};

		struct Vector3
		{
			f32 X = 0.f;
			f32 Y = 0.f;
			f32 Z = 0.f;
		};

		template<int T>
		struct Vector
		{
			f32 elements[T];

			template<int Index>
			f32 At()
			{
				static_assert(Index < T, "Out of bounds! This vector does not contain that many elements");
				return elements[Index];
			}			
		};


		constexpr Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
		{
			Vector2 res;
			res.X = lhs.X + rhs.X;
			res.Y = lhs.Y + rhs.Y;
			return res;
		}

		constexpr Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
		{
			Vector3 res;
			res.X = lhs.X + rhs.X;
			res.Y = lhs.Y + rhs.Y;
			res.Z = lhs.Z + rhs.Z;
			return res;
		}

		constexpr Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
		{
			Vector2 res;
			res.X = lhs.X - rhs.X;
			res.Y = lhs.Y - rhs.Y;
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
	}
}