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

#include <core/math/rectangle.hpp>

TEST(RectangleTest, Constructor) {
	dengine::math::Rectangle rect {12.0f, 10.0f, 10.0f, 20.0f};
	SUCCEED();
}

#ifndef NDEBUG
TEST(RectangleTest, WidthCannotBeNegative) {
	EXPECT_DEATH(dengine::math::Rectangle rect(0.0f, 0.0f, -5.0f, 10.0f), "width");
	SUCCEED();
}

TEST(RectangleTest, HeightCannotBeNegative) {
	EXPECT_DEATH(dengine::math::Rectangle rect(0.0f, 0.0f, 5.0f, -10.0f), "height");
	SUCCEED();
}
#endif

TEST(RectangleTest, Getters) {
	dengine::math::Rectangle rect {3.0f, 5.0f, 7.0f, 11.0f};

	EXPECT_FLOAT_EQ(rect.x(), 3.0f);
	EXPECT_FLOAT_EQ(rect.y(), 5.0f);
	EXPECT_FLOAT_EQ(rect.w(), 7.0f);
	EXPECT_FLOAT_EQ(rect.h(), 11.0f);

	SUCCEED();
}

TEST(RectangleTest, Setters) {
	dengine::math::Rectangle rect {3.0f, 5.0f, 7.0f, 11.0f};

	rect.set_position(13.0f, 17.0f);

	EXPECT_FLOAT_EQ(rect.x(), 13.0f);
	EXPECT_FLOAT_EQ(rect.y(), 17.0f);

	rect.set_size(19.0f, 23.0f);
	
	EXPECT_FLOAT_EQ(rect.w(), 19.0f);
	EXPECT_FLOAT_EQ(rect.h(), 23.0f);

	SUCCEED();
}
