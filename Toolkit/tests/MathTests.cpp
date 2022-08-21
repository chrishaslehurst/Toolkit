#include <catch2/catch_test_macros.hpp>

#include "CoreMinimal.h"
#include "Vector.h"
#include "Matrix.h"

TEST_CASE("Vector addition works", "[math]") 
{
	toolkit::math::Vector<2> vec2_1;
	toolkit::math::Vector<2> vec2_2;
	toolkit::math::Vector<3> vec3_1;
	toolkit::math::Vector<3> vec3_2;

	vec3_1.x = 5.f;
	vec3_1.y = 0.f;
	vec3_1.z = 3.f;

	vec3_2.x = 0.f;
	vec3_2.y = 4.f;
	vec3_2.z = 19.f;
	
	REQUIRE(vec2_1.x == 0.f);

	toolkit::math::Vector<3> result;
	result = vec3_1 + vec3_2;

	REQUIRE(result.x == 5.f);
	REQUIRE(result.y == 4.f);
	REQUIRE(result.z == 22.f);
	
}

TEST_CASE("Vector Dot Product Works", "[math]")
{
	toolkit::math::Vector<2> vec2_1;
	toolkit::math::Vector<2> vec2_2;
	toolkit::math::Vector<3> vec3_1;
	toolkit::math::Vector<3> vec3_2;

	vec3_1.x = -1.f;
	vec3_1.y = 1.f;
	vec3_1.z = -1.f;

	vec3_2.x = 1.f;
	vec3_2.y = -1.f;
	vec3_2.z = 1.f;

	f32 result = toolkit::math::DotProduct(vec3_1, vec3_2);

	REQUIRE(result == -3.f);
}