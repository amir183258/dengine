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

#include <memory>

#include <gtest/gtest.h>

#include <core/window/sdl_init.hpp>
#include <core/window/sdl_window.hpp>
#include <core/graphics/sdl_renderer.hpp>

class SDLRendererTest : public ::testing::Test {
private:
protected:
	dengine::SDLInit init {};
	std::unique_ptr<dengine::SDLWindow> window;
	std::unique_ptr<dengine::SDLRenderer> renderer;

	void SetUp() override {
		ASSERT_TRUE(init.initialize());

		window = std::make_unique<dengine::SDLWindow>();
		renderer = std::make_unique<dengine::SDLRenderer>(*window);
	}
};

TEST_F(SDLRendererTest, ConstructUsingSDLWindow) {
	ASSERT_TRUE(window->is_valid());
	ASSERT_TRUE(renderer->is_valid());

	SUCCEED();
}

TEST_F(SDLRendererTest, RenderClear) {
	renderer->clear();

	SUCCEED();
}
