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

#include <core/graphics/sdl_renderer.hpp>
#include <core/window/sdl_window.hpp>

namespace dengine {
	SDLRenderer::SDLRenderer(SDLWindow &window): Renderer {window}
	{
		renderer_ = SDL_CreateRenderer(&window.get_sdl_window_handle(), nullptr);
	}

	void SDLRenderer::clear() {
		SDL_RenderClear(renderer_);
	}

	SDL_Renderer& SDLRenderer::get_sdl_renderer_handle() const {
		return *renderer_;
	}

	SDLRenderer::~SDLRenderer() {
		if (renderer_)
			SDL_DestroyRenderer(renderer_);
	}
}
