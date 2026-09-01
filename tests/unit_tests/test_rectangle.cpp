#include <cmath>
#include <gtest/gtest.h>

#include "core/math/rectangle.hpp"

TEST(RectangleTest, Constructor) {
	math::Rectangle rect {12.0f, 10.0f, 10.0f, 20.0f};
	SUCCEED();
}

#ifndef NDEBUG
TEST(RectangleTest, WidthCannotBeNegative) {
	EXPECT_DEATH(math::Rectangle rect(0.0f, 0.0f, -5.0f, 10.0f), "width");
	SUCCEED();
}

TEST(RectangleTest, HeightCannotBeNegative) {
	EXPECT_DEATH(math::Rectangle rect(0.0f, 0.0f, 5.0f, -10.0f), "height");
	SUCCEED();
}
#endif

TEST(RectangleTest, Getters) {
	math::Rectangle rect {3.0f, 5.0f, 7.0f, 11.0f};

	EXPECT_FLOAT_EQ(rect.x(), 3.0f);
	EXPECT_FLOAT_EQ(rect.y(), 5.0f);
	EXPECT_FLOAT_EQ(rect.w(), 7.0f);
	EXPECT_FLOAT_EQ(rect.h(), 11.0f);

	SUCCEED();
}

TEST(RectangleTest, Setters) {
	math::Rectangle rect {3.0f, 5.0f, 7.0f, 11.0f};

	rect.set_position(13.0f, 17.0f);

	EXPECT_FLOAT_EQ(rect.x(), 13.0f);
	EXPECT_FLOAT_EQ(rect.y(), 17.0f);

	rect.set_size(19.0f, 23.0f);
	
	EXPECT_FLOAT_EQ(rect.w(), 19.0f);
	EXPECT_FLOAT_EQ(rect.h(), 23.0f);

	SUCCEED();
}
