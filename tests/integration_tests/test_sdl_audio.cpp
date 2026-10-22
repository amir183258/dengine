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
#include <core/audio/sdl_mixer.hpp>
#include <core/audio/sdl_audio.hpp>

// for test assets
#include <config.hpp>

class SDLAudioTest : public ::testing::Test {
private:
protected:
	dengine::SDLInit init {};
	std::unique_ptr<dengine::SDLMixer> mixer;
	std::unique_ptr<dengine::SDLAudio> audio;

	std::string audio_path = dengine::config::TEST_ASSETS_PATH +
		"/test_audio.wav";

	void SetUp() override {
		ASSERT_TRUE(init.initialize());

		mixer = std::make_unique<dengine::SDLMixer>();
		ASSERT_TRUE(mixer->is_valid());

		audio = std::make_unique<dengine::SDLAudio>(*mixer, audio_path);
		ASSERT_TRUE(audio->is_valid());
	}
};

TEST_F(SDLAudioTest, AudioIsValid) {
	EXPECT_TRUE(audio->is_valid());

	SUCCEED();
}

TEST_F(SDLAudioTest, PlayAudio) {
	audio->play();

	SUCCEED();
}
