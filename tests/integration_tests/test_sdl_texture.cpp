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

#include <string>
#include <memory>

#include <gtest/gtest.h>

#include <core/window/sdl_init.hpp>
#include <core/window/sdl_window.hpp>
#include <core/graphics/sdl_renderer.hpp>
#include <core/graphics/sdl_texture.hpp>

// for test assets
#include <config.hpp>

class SDLTexture : public ::testing::Test {
private:
protected:
	dengine::SDLInit init {};
	std::unique_ptr<dengine::SDLWindow> window;
	std::unique_ptr<dengine::SDLRenderer> renderer;

	std::string texture_path = dengine::config::TEST_ASSETS_PATH +
		"/test_texture.png";
	std::unique_ptr<dengine::SDLTexture> texture;

	void SetUp() override {
		ASSERT_TRUE(init.initialize());

		window = std::make_unique<dengine::SDLWindow>();
		ASSERT_TRUE(window->is_valid());

		renderer = std::make_unique<dengine::SDLRenderer>(*window);
		ASSERT_TRUE(renderer->is_valid());

		texture = std::make_unique<dengine::SDLTexture>(*renderer,
				texture_path);
		ASSERT_TRUE(texture->is_valid());
	}
};

TEST_F(SDLTexture, DefaultConstructor) {
	dengine::SDLTexture texture2 {};

	EXPECT_FALSE(texture2.is_valid());

	SUCCEED();
}

TEST_F(SDLTexture, MoveConstructor) {
	dengine::SDLTexture texture1 {*renderer, texture_path};
	EXPECT_TRUE(texture1.is_valid());

	dengine::SDLTexture texture2 {std::move(texture1)};
	EXPECT_TRUE(texture2.is_valid());

	EXPECT_FALSE(texture1.is_valid());

	SUCCEED();
}

TEST_F(SDLTexture, MoveAssignment) {
	dengine::SDLTexture texture1 {*renderer, texture_path};
	EXPECT_TRUE(texture1.is_valid());

	dengine::SDLTexture texture2 {};
	EXPECT_FALSE(texture2.is_valid());

	texture2 = std::move(texture1);

	EXPECT_FALSE(texture1.is_valid());
	EXPECT_TRUE(texture2.is_valid());

	SUCCEED();
}

TEST_F(SDLTexture, WidthAndHeight) {
	EXPECT_EQ(texture->width(), 300);
	EXPECT_EQ(texture->height(), 150);

	SUCCEED();
}
