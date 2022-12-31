#include <catch2/catch_test_macros.hpp>

#include "CoreMinimal.h"
#include "Vector.h"
#include "Matrix.h"

TEST_CASE("Vector addition works", "[math]") 
{
	tk::Vector3 vec3_1{ 5.f, 0.f, 3.f };
	tk::Vector3 vec3_2;

	vec3_2.X = 0.f;
	vec3_2.Y = 4.f;
	vec3_2.Z = 19.f;

	tk::Vector3 result;
	result = vec3_1 + vec3_2;

	REQUIRE(result.X == 5.f);
	REQUIRE(result.Y == 4.f);
	REQUIRE(result.Z == 22.f);
	
}

TEST_CASE("Vector Dot Product Works", "[math]")
{
	tk::Vector3 vec3_1;
	tk::Vector3 vec3_2;

	vec3_1.X = -1.f;
	vec3_1.Y = 1.f;
	vec3_1.Z = -1.f;

	vec3_2.X = 1.f;
	vec3_2.Y = -1.f;
	vec3_2.Z = 1.f;

	f32 result = tk::vector::DotProduct(vec3_1, vec3_2);

	REQUIRE(result == -3.f);
}

TEST_CASE("Vector Cross Product Works", "[math]")
{
	tk::Vector3 vec3_1{ 3.f, -3.f, 1.f };
	tk::Vector3 vec3_2{ 4.f, 9.f, 2.f };

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

TEST_CASE("Matrix Multiplication Works", "[math]")
{
	using Matrix4 = tk::Matrix<float, 4, 4>;
	using Matrix3 = tk::Matrix<double, 3, 3>;
	using Matrix2 = tk::Matrix<float, 2, 2>;

	Matrix4 FourByFourM1 = Matrix4::Identity();
	Matrix4 FourByFourM2 = Matrix4::Identity();

	Matrix3 ThreeByThreeM1 = Matrix3::Identity();
	Matrix3 ThreeByThreeM2 = Matrix3::Identity();

	Matrix4 IdentityTimesIdentityFour = FourByFourM1 * FourByFourM2;
	Matrix3 IdentityTimesIdentityThree = ThreeByThreeM1 * ThreeByThreeM2;

	REQUIRE(IdentityTimesIdentityThree == Matrix3::Identity());
	REQUIRE(IdentityTimesIdentityFour == Matrix4::Identity());
}