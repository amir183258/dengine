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

#include <core/window/sdl_init.hpp>

namespace dengine {
	bool SDLInit::initialized = false;

	bool SDLInit::initialize() {
		if (is_initialized())
			return true;

		if (!SDL_Init(SDL_INIT_VIDEO))
			return false;

		initialized = true;
		return true;
	}

	void SDLInit::shutdown() {
		if (!is_initialized())
			return;

		SDL_Quit();
		initialized = false;
	}

	bool SDLInit::is_initialized() const {
		return initialized;
	}
}
