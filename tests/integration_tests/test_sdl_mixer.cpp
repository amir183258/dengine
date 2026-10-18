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

#include <core/audio/sdl_mixer.hpp>

TEST(SDLMixerTest, DefaultConstructor) {
	dengine::SDLMixer mixer {};

	EXPECT_TRUE(mixer.is_valid());

	SUCCEED();
}
