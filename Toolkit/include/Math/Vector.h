#pragma once

#include "CoreMinimal.h"

namespace toolkit
{
	namespace math
	{
		namespace vec 
		{
			template <int> struct Members { };
			template <> struct Members<2> { f32 x = 0.f; f32 y = 0.f; };
			template <> struct Members<3> { f32 x = 0.f; f32 y = 0.f; f32 z = 0.f; };
		}

		template<int T>
		struct Vector : vec::Members<T>
		{
			static_assert(T == 3 || T == 2, "Only supports 2 or 3 elements");
		};

		using Vector2 = Vector<2>;
		using Vector3 = Vector<3>;

		template<int T>
		constexpr Vector<T> operator+(const Vector<T>& lhs, const Vector<T>& rhs)
		{
			Vector<T> res;
			res.x = lhs.x + rhs.x;
			res.y = lhs.y + rhs.y;
			if constexpr (T > 2)
			{
				res.z = lhs.z + rhs.z;
			}
			return res;
		}

		template<int T>
		constexpr Vector<T> operator-(const Vector<T>& lhs, const Vector<T>& rhs)
		{
			Vector<T> res;
			res.x = lhs.x - rhs.x;
			res.y = lhs.y - rhs.y;
			if constexpr (T > 2)
			{
				res.z = lhs.z - rhs.z;
			}
			return res;
		}

		template<int T>
		constexpr float DotProduct(const Vector<T>& lhs, const Vector<T>& rhs)
		{
			if constexpr (T == 2)
			{
				return (lhs.x * rhs.x) + (lhs.y * rhs.y);
			}
			else if constexpr (T == 3)
			{
				return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
			}
		}
	}
}