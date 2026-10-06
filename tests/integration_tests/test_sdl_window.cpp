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
#include <memory>

#include <gtest/gtest.h>

#include <core/window/sdl_init.hpp>
#include <core/window/sdl_window.hpp>

class SDLWindowTest : public ::testing::Test {
private:
protected:
	dengine::SDLInit init {};
	std::unique_ptr<dengine::SDLWindow> window;

	void SetUp() override {
		ASSERT_TRUE(init.initialize());

		window = std::make_unique<dengine::SDLWindow>();
		ASSERT_TRUE(window->is_valid());
	}
};

TEST_F(SDLWindowTest, ConstructorWithParameters) {
	dengine::SDLWindow window2 {"Window2", 300, 100};

	EXPECT_EQ(window2.get_width(), 300);
	EXPECT_EQ(window2.get_height(), 100);

	SUCCEED();
}

TEST_F(SDLWindowTest, MoveConstructor) {
	dengine::SDLWindow window1 {"Window", 300, 100};
	dengine::SDLWindow window2 {std::move(window1)};

	EXPECT_FALSE(window1.is_valid());

	EXPECT_TRUE(window2.is_valid());
	EXPECT_EQ(window2.get_width(), 300);
	EXPECT_EQ(window2.get_height(), 100);

	SUCCEED();
}

TEST_F(SDLWindowTest, MoveAssignment) {
	dengine::SDLWindow window1 {"Window1", 300, 100};
	dengine::SDLWindow window2 {"Window2", 200, 150};

	window2 = std::move(window1);

	EXPECT_FALSE(window1.is_valid());

	EXPECT_TRUE(window2.is_valid());
	EXPECT_EQ(window2.get_width(), 300);
	EXPECT_EQ(window2.get_height(), 100);

	SUCCEED();
}

TEST_F(SDLWindowTest, NativeHandle) {
	EXPECT_TRUE(&window->get_sdl_window_handle() != nullptr);

	SUCCEED();
}
