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

#include <core/window/sdl_init.hpp>

TEST(SDLInitTest, DefaultConstructor) {
	dengine::SDLInit init {};
	SUCCEED();
}

TEST(SDLInitTest, InitializeAndShutdown) {
	dengine::SDLInit init {};

	EXPECT_TRUE(init.initialize());
	EXPECT_TRUE(init.is_initialized());

	init.shutdown();

	EXPECT_FALSE(init.is_initialized());

	SUCCEED();
}

TEST(SDLInitTest, CreateTwoClass) {
	dengine::SDLInit init1 {};
	dengine::SDLInit init2 {};

	EXPECT_TRUE(init1.initialize());

	EXPECT_TRUE(init1.is_initialized());
	EXPECT_TRUE(init2.is_initialized());

	// initialize again should return true
	EXPECT_TRUE(init1.initialize());
	EXPECT_TRUE(init2.initialize());

	// now shutdown
	init2.shutdown();

	EXPECT_FALSE(init1.is_initialized());
	EXPECT_FALSE(init2.is_initialized());

	SUCCEED();
}
