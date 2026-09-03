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

#include <gtest/gtest.h>

#include <core/graphics/color.hpp>

TEST(ColorTest, Constructor) {
	Color color {};

	EXPECT_EQ(color.r, 0);
	EXPECT_EQ(color.g, 0);
	EXPECT_EQ(color.b, 0);
	EXPECT_EQ(color.a, 255);

	SUCCEED();
}

TEST(ColorTest, EqualityCompare) {
	Color color1 {};
	Color color2 {};

	EXPECT_TRUE(color1 == color2);

	// make color1 red
	color1.r = 255;

	EXPECT_FALSE(color1 == color2);

	SUCCEED();
}
