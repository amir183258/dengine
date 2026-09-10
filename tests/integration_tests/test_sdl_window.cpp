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

#include <utility>

#include <gtest/gtest.h>

#include <core/window/sdl_init.hpp>
#include <core/window/sdl_window.hpp>

TEST(SDLWindowTest, DefaultConstructor) {
	dengine::SDLInit init {};
	bool ok = init.initialize();
	EXPECT_TRUE(ok);

	dengine::SDLWindow window {};

	EXPECT_TRUE(window.is_valid());

	SUCCEED();
}

TEST(SDLWindowTest, ConstructorWithParameters) {
	dengine::SDLInit init {};
	bool ok = init.initialize();
	EXPECT_TRUE(ok);

	dengine::SDLWindow window {"Window", 300, 100};

	EXPECT_EQ(window.get_width(), 300);
	EXPECT_EQ(window.get_height(), 100);

	SUCCEED();
}

TEST(SDLWindowTest, MoveConstructor) {
	dengine::SDLInit init {};
	bool ok = init.initialize();
	EXPECT_TRUE(ok);

	dengine::SDLWindow window1 {"Window", 300, 100};
	dengine::SDLWindow window2 {std::move(window1)};

	EXPECT_FALSE(window1.is_valid());

	EXPECT_TRUE(window2.is_valid());
	EXPECT_EQ(window2.get_width(), 300);
	EXPECT_EQ(window2.get_height(), 100);

	SUCCEED();
}

TEST(SDLWindowTest, MoveAssignment) {
	dengine::SDLInit init {};
	bool ok = init.initialize();
	EXPECT_TRUE(ok);

	dengine::SDLWindow window1 {"Window1", 300, 100};
	dengine::SDLWindow window2 {"Window2", 200, 150};

	window2 = std::move(window1);

	EXPECT_FALSE(window1.is_valid());

	EXPECT_TRUE(window2.is_valid());
	EXPECT_EQ(window2.get_width(), 300);
	EXPECT_EQ(window2.get_height(), 100);

	SUCCEED();
}
