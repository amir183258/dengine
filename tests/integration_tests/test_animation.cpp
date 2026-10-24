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
#include <cstdint>
#include <memory>

#include <gtest/gtest.h>

#include <core/window/sdl_init.hpp>
#include <core/window/sdl_window.hpp>
#include <core/graphics/sdl_renderer.hpp>
#include <core/graphics/sdl_texture.hpp>
#include <core/graphics/texture.hpp>
#include <engine/animation.hpp>

// for test assets
#include <config.hpp>

class AnimationTest : public ::testing::Test {
private:
protected:
	dengine::SDLInit init {};
	std::unique_ptr<dengine::SDLWindow> window;
	std::unique_ptr<dengine::SDLRenderer> renderer;

	std::string animation_path = dengine::config::TEST_ASSETS_PATH +
		"/test_animation.png";

	std::unique_ptr<dengine::Texture> animation_texture;

	std::unique_ptr<dengine::Animation> animation;

	void SetUp() override {
		ASSERT_TRUE(init.initialize());

		window = std::make_unique<dengine::SDLWindow>();
		ASSERT_TRUE(window->is_valid());

		renderer = std::make_unique<dengine::SDLRenderer>(*window);
		ASSERT_TRUE(renderer->is_valid());

		animation_texture = std::make_unique<dengine::SDLTexture>(*renderer,
				animation_path);

		animation = std::make_unique<dengine::Animation>(animation_texture.get(),
				5, 0.13f);
		ASSERT_TRUE(animation->is_valid());
	}
};

TEST_F(AnimationTest, UpdateAnimation) {
	animation->update(2.3f);
	animation->update(3.4f);

	SUCCEED();
}

TEST_F(AnimationTest, ResetAnimation) {
	animation->update(2.3f);
	animation->update(3.4f);

	animation->reset();

	SUCCEED();
}

TEST_F(AnimationTest, GetDimensions) {
	EXPECT_EQ(animation->width(), 50);
	EXPECT_EQ(animation->height(), 50);

	SUCCEED();
}

TEST_F(AnimationTest, GetFrameInformation) {
	animation->reset();
	dengine::FrameInfo info = animation->get_current_frame_info();

	EXPECT_EQ(info.rect.x(), 0);
	EXPECT_EQ(info.rect.y(), 0);
	EXPECT_EQ(info.rect.w(), 50);
	EXPECT_EQ(info.rect.h(), 50);

	// next frame
	animation->update(0.14f);
	info = animation->get_current_frame_info();

	EXPECT_EQ(info.rect.x(), 50);
	EXPECT_EQ(info.rect.y(), 0);
	EXPECT_EQ(info.rect.w(), 50);
	EXPECT_EQ(info.rect.h(), 50);

	SUCCEED();
}

TEST_F(AnimationTest, IsFinished) {
	animation->reset();
	animation->set_loop(false);

	animation->update(10.0f);

	EXPECT_TRUE(animation->is_finished());

	SUCCEED();
}
