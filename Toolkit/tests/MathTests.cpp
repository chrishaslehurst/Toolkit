#include <catch2/catch_test_macros.hpp>

#include "CoreMinimal.h"
#include "Vector.h"
#include "Matrix.h"

TEST_CASE("Vector addition works", "[math]") 
{
	toolkit::math::Vector<2> vec2;
	toolkit::math::Vector<3> vec3;
	
	REQUIRE(vec2.X == 0.f);
	
}