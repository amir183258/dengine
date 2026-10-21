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

#include <core/audio/sdl_audio.hpp>
#include <core/audio/sdl_mixer.hpp>

namespace dengine {

	SDLAudio::SDLAudio(SDLMixer &mixer, const std::string &path) {
		audio_ = MIX_LoadAudio(&mixer.get_sdl_mixer_handle(), path.c_str(), true);
	}

	MIX_Audio& SDLAudio::get_sdl_audio_handle() const {
		return *audio_;
	}

	SDLAudio::~SDLAudio() {
		if (audio_)
			MIX_DestroyAudio(audio_);
	}
}
