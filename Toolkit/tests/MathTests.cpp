#include <catch2/catch_test_macros.hpp>

#include "CoreMinimal.h"
#include "Vector.h"
#include "Matrix.h"

TEST_CASE("Vector addition works", "[math]") 
{
	tk::Vector2 vec2_1{ 1.f, 2.f };
	tk::Vector2 vec2_2;
	tk::Vector3 vec3_1{ 5.f, 0.f, 3.f };
	tk::Vector3 vec3_2;

	vec3_2.x = 0.f;
	vec3_2.y = 4.f;
	vec3_2.z = 19.f;
	
	REQUIRE(vec2_1.x == 1.f);

	tk::Vector<3> result;
	result = vec3_1 + vec3_2;

	REQUIRE(result.x == 5.f);
	REQUIRE(result.y == 4.f);
	REQUIRE(result.z == 22.f);
	
}

TEST_CASE("Vector Dot Product Works", "[math]")
{
	tk::Vector<2> vec2_1;
	tk::Vector<2> vec2_2;
	tk::Vector<3> vec3_1;
	tk::Vector<3> vec3_2;

	vec3_1.x = -1.f;
	vec3_1.y = 1.f;
	vec3_1.z = -1.f;

	vec3_2.x = 1.f;
	vec3_2.y = -1.f;
	vec3_2.z = 1.f;

	f32 result = tk::vector::DotProduct(vec3_1, vec3_2);

	REQUIRE(result == -3.f);
}

TEST_CASE("Vector Cross Product Works", "[math]")
{
	tk::Vector<3> vec3_1 {3.f, -3.f, 1.f};
	tk::Vector<3> vec3_2 {4.f, 9.f, 2.f};

	tk::Vector3 result = tk::vector::CrossProduct(vec3_1, vec3_2);
	// #todo-ch 28/08/2022: write some proper tests..
	REQUIRE(result == tk::Vector3{-15.f, -2.f, 39.f});
}

TEST_CASE("Distance and Length Works", "[math]")
{
	tk::Vector3 origin;
	tk::Vector3 ones{ 1.f, 1.f, 1.f };
	tk::Vector3 fives{ 5.f, 5.f, 5.f };

	REQUIRE(tk::vector::DistSquared(ones, origin) == 3.f);
	REQUIRE(tk::vector::Dist(ones, origin) == sqrt(3.f));

}