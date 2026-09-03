/*
 * Copyright (c) 2026 dengine project
 *
 * This is the source code of the dengine project.
 * It is licensed under the MIT License; you should have received a copy
 * of the license in this archive (see LICENSE).
 *
 * Author: Amir Hossein Ebrahimi
 *
 */

#include <cmath>
#include <gtest/gtest.h>

#include <core/math/vector_2d.hpp>

TEST(Vector2DTest, Constructor) {
	dengine::math::Vector2D vec;
	EXPECT_EQ(vec.x, 0);
	EXPECT_EQ(vec.y, 0);

	dengine::math::Vector2D vec2 {1, 2};
	EXPECT_EQ(vec2.x, 1);
	EXPECT_EQ(vec2.y, 2);
}

TEST(Vector2DTest, ChangeCoordinates) {
	dengine::math::Vector2D vec;

	vec.x = 4;
	EXPECT_EQ(vec.x, 4);

	vec.y = 6;
	EXPECT_EQ(vec.y, 6);
}

TEST(Vector2DTest, ComputeLength) {
	dengine::math::Vector2D vec {3, 4};
	EXPECT_EQ(vec.length(), 5);

	vec.x = -3;
	EXPECT_EQ(vec.length(), 5);

	vec.x = 0;
	vec.y = 0;
	EXPECT_EQ(vec.length(), 0);
}

TEST(Vector2DTest, CompueLengthSquared) {
	dengine::math::Vector2D vec {3, 4};
	EXPECT_EQ(vec.length_squared(), 25);

	vec.x = 0;
	vec.y = 0;
	EXPECT_EQ(vec.length_squared(), 0);
}

TEST(Vector2DTest, CompueNormalized) {
	dengine::math::Vector2D vec {2, 2};

	dengine::math::Vector2D result {vec.normalized()};

	EXPECT_NEAR(result.x, std::sqrt(2.0f) / 2, 0.1f);
	EXPECT_NEAR(result.y, std::sqrt(2.0f) / 2, 0.1f);
}

TEST(Vector2DTest, AddAssignOperator) {
	dengine::math::Vector2D a {3, 4};
	dengine::math::Vector2D b {7, 11};

	a += b;

	EXPECT_EQ(a.x, 10);
	EXPECT_EQ(a.y, 15);
}

TEST(Vector2DTest, MinusAssignOperator) {
	dengine::math::Vector2D a {3, 4};
	dengine::math::Vector2D b {7, 11};

	a -= b;

	EXPECT_EQ(a.x, -4);
	EXPECT_EQ(a.y, -7);
}

TEST(Vector2DTest, MultiplicationAssignOperator) {
	dengine::math::Vector2D a {3, 4};
	float s = 4;

	a *= s;

	EXPECT_EQ(a.x, 12);
	EXPECT_EQ(a.y, 16);
}

TEST(Vector2DTest, AddOperator) {
	dengine::math::Vector2D a {1, 2};
	dengine::math::Vector2D b {3, 4};

	dengine::math::Vector2D result {a + b};

	EXPECT_EQ(result.x, 4);
	EXPECT_EQ(result.y, 6);
}

TEST(Vector2DTest, MinusOperator) {
	dengine::math::Vector2D a {1, 2};
	dengine::math::Vector2D b {3, 4};

	dengine::math::Vector2D result {a - b};

	EXPECT_EQ(result.x, -2);
	EXPECT_EQ(result.y, -2);
}

TEST(Vector2DTest, MultiplicationOperator) {
	dengine::math::Vector2D a {1, 2};
	float s = 3;

	dengine::math::Vector2D result {a * s};

	EXPECT_EQ(result.x, 3);
	EXPECT_EQ(result.y, 6);
	
	result = {s * a};

	EXPECT_EQ(result.x, 3);
	EXPECT_EQ(result.y, 6);
}

TEST(Vector2DTest, CompueDistance) {
	dengine::math::Vector2D a {0, 1};
	dengine::math::Vector2D b {2, 3};

	float result = distance(a, b);

	EXPECT_NEAR(result, std::sqrt(8.0f), 0.1f);
}

TEST(Vector2DTest, ComputeDistanceSquared) {
	dengine::math::Vector2D a {0, 1};
	dengine::math::Vector2D b {2, 3};

	float result = distance_squared(a, b);

	EXPECT_EQ(result, 8);
}
