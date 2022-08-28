#pragma once

#include "CoreMinimal.h"
#include <type_traits>

namespace tk
{
	namespace vec 
	{
		template <int> 
		struct Members 
		{ };

		template <> 
		struct Members<2> 
		{ 
			f32 x = 0.f; 
			f32 y = 0.f; 
			Members() = default; 
			Members(f32 inX, f32 inY) :x(inX), y(inY) {} 
		};
			
		template <> 
		struct Members<3> 
		{ 
			f32 x = 0.f; 
			f32 y = 0.f; 
			f32 z = 0.f; 
			Members() = default; 
			Members(f32 inX, f32 inY, f32 inZ) :x(inX), y(inY), z(inZ) {}
		};
	}

	template<int T>
	struct Vector : vec::Members<T>
	{
		using Mems = vec::Members<T>;
		Vector() = default;

		Vector(f32 inX, f32 inY)
			: Mems(inX, inY)
		{
			static_assert(T == 2, "Wrong Constructor Used");
		}

		Vector(f32 inX, f32 inY, f32 inZ)
			: Mems(inX, inY, inZ)
		{
			static_assert(T == 3, "Wrong Constructor Used");
		}

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
	constexpr bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
	{
		if constexpr (T == 2)
		{
			return lhs.x == rhs.x && lhs.y == rhs.y;
		}
		else if constexpr (T == 3)
		{
			return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
		}	
	}

	namespace vector
	{

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

		template<int T>
		constexpr Vector<T> CrossProduct(const Vector<T>& lhs, const Vector<T>& rhs)
		{
			if constexpr (T == 3)
			{
				return Vector<T>(((lhs.y * rhs.z) - (lhs.z * rhs.y)), ((lhs.z * rhs.x) - (lhs.x * rhs.z)), ((lhs.x * rhs.y) - (lhs.y * rhs.x)));
			}
		}

		template<int T>
		constexpr float DistSquared(const Vector<T>& a, const Vector<T>& b)
		{
			if constexpr (T == 2)
			{
				Vector2 between = a - b;
				return (between.x * between.x) + (between.y * between.y);
			}
			else if constexpr (T == 3)
			{
				Vector3 between = a - b;
				return (between.x * between.x) + (between.y * between.y) + (between.z * between.z);
			}
		}

		template<int T>
		constexpr float Dist(const Vector<T>& a, const Vector<T>& b)
		{
			return sqrt(DistSquared(a, b));
		}

		template<int T>
		constexpr float LengthSquared(const Vector<T>& vec)
		{
			if constexpr (T == 2)
			{
				return (vec.x * vec.x) + (vec.y * vec.y);
			}
			else if constexpr (T == 3)
			{

				return (vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z);
			}
		}

		template<int T>
		constexpr float Length(const Vector<T>& vec)
		{
			return sqrt(LengthSquared(vec));
		}
	}
}