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

#include <core/graphics/color.hpp>
#include <core/window/sdl_init.hpp>
#include <core/window/sdl_window.hpp>
#include <core/graphics/sdl_renderer.hpp>
#include <core/graphics/sdl_text_maker.hpp>
#include <core/graphics/texture.hpp>

// for test assets
#include <config.hpp>

class SDLTextMakerTest : public ::testing::Test {
private:
protected:
	dengine::SDLInit init {};
	std::unique_ptr<dengine::SDLWindow> window;
	std::unique_ptr<dengine::SDLRenderer> renderer;
	std::unique_ptr<dengine::SDLTextMaker> text_maker;

	std::string font_path = dengine::config::TEST_ASSETS_PATH +
		"/press_start_font.ttf";
	std::unique_ptr<dengine::Texture> texture;

	void SetUp() override {
		ASSERT_TRUE(init.initialize());

		window = std::make_unique<dengine::SDLWindow>();
		ASSERT_TRUE(window->is_valid());

		renderer = std::make_unique<dengine::SDLRenderer>(*window);
		ASSERT_TRUE(renderer->is_valid());

		// should send the raw pointer as the parameter
		text_maker = std::make_unique<dengine::SDLTextMaker>(renderer.get(),
				font_path, 24);

		ASSERT_TRUE(text_maker->is_valid());
	}
};

TEST_F(SDLTextMakerTest, CreateText) {
	std::unique_ptr<dengine::Texture> text_texture =
		text_maker->make_text("Hello, World!");

	SUCCEED();
}

TEST_F(SDLTextMakerTest, ChangeTextColor) {
	text_maker->set_color(Colors::Red);

	std::unique_ptr<dengine::Texture> text_texture =
		text_maker->make_text("Hello, World!");

	SUCCEED();
}
