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

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>

#include <core/audio/sdl_mixer.hpp>

namespace dengine {
	SDLMixer::SDLMixer() {
		mixer_ = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, nullptr);
	}

	MIX_Mixer& SDLMixer::get_sdl_mixer_handle() const {
		return *mixer_;
	}

	SDLMixer::~SDLMixer() {
		if (mixer_)
			MIX_DestroyMixer(mixer_);
	}
}
