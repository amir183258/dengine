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

#include <core/sdl_provider.hpp>
#include <core/window/init.hpp>
#include <core/window/window.hpp>
#include <core/graphics/renderer.hpp>
#include <core/graphics/texture.hpp>
#include <core/time/time_provider.hpp>

// for test assets
#include <config.hpp>

TEST(SDLProviderTest, CreateTexture) {
	dengine::SDLProvider provider {};

	// init
	std::unique_ptr<dengine::Init> init = provider.create_init();
	init->initialize();

	// create window
	std::unique_ptr<dengine::Window> window = provider.create_window("Test Window",
			640, 480);
	ASSERT_NE(window, nullptr);

	// create renderer
	std::unique_ptr<dengine::Renderer> renderer = provider.create_renderer(*window);
	ASSERT_NE(renderer, nullptr);

	// create texture
	std::string texture_path = dengine::config::TEST_ASSETS_PATH +
		"/test_texture.png";
	std::unique_ptr<dengine::Texture> texture = provider.create_texture(*renderer,
			texture_path);
	ASSERT_NE(texture, nullptr);

	SUCCEED();
}

TEST(SDLProviderTest, CreateTimeProvider) {
	dengine::SDLProvider provider {};

	// init
	std::unique_ptr<dengine::Init> init = provider.create_init();
	init->initialize();

	std::unique_ptr<dengine::TimeProvider> time_provider =
		provider.create_time_provider();

	SUCCEED();
}
