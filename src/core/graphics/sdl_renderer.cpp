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

#include <core/graphics/color.hpp>
#include <core/graphics/sdl_renderer.hpp>
#include <core/window/sdl_window.hpp>
#include <core/graphics/texture.hpp>
#include <core/graphics/sdl_texture.hpp>

namespace dengine {
	SDLRenderer::SDLRenderer(SDLWindow &window) {
		renderer_ = SDL_CreateRenderer(&window.get_sdl_window_handle(), nullptr);
	}

	SDL_Renderer& SDLRenderer::get_sdl_renderer_handle() const {
		return *renderer_;
	}

	void SDLRenderer::clear() {
		SDL_RenderClear(renderer_);
	}

	void SDLRenderer::set_draw_color(const Color &color) {
		SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
	}

	void SDLRenderer::present() {
		SDL_RenderPresent(renderer_);
	}

	void SDLRenderer::draw_point(float x, float y) {
		SDL_RenderPoint(renderer_, x, y);
	}

	void SDLRenderer::draw_line(float x1, float y1, float x2, float y2) {
		SDL_RenderLine(renderer_, x1, y1, x2, y2);
	}

	void SDLRenderer::draw_rect(float x, float y, float w, float h) {
		SDL_FRect rect {x, y, w, h};
		SDL_RenderRect(renderer_, &rect);
	}

	void SDLRenderer::fill_rect(float x, float y, float w, float h) {
		SDL_FRect rect {x, y, w, h};
		SDL_RenderFillRect(renderer_, &rect);
	}

	void SDLRenderer::draw_texture(Texture &texture, float src_x, float src_y,
			float src_w, float src_h, float dest_x, float dest_y,
			float dest_w, float dest_h)
	{
		SDLTexture &sdl_texture = static_cast<SDLTexture&>(texture);
		SDL_Texture &native_sdl_texture = sdl_texture.get_sdl_texture_handle();

		SDL_FRect src_rect {src_x, src_y, src_w, src_h};
		SDL_FRect dest_rect {dest_x, dest_y, dest_w, dest_h};

		if (dest_rect.w <= 0 || dest_rect.h <= 0) {
			dest_rect.w = (float)texture.width();
			dest_rect.h = (float)texture.height();
		}

		if (src_rect.w <= 0 || src_rect.h <= 0)
			SDL_RenderTexture(renderer_, &native_sdl_texture, nullptr, &dest_rect);
		else
			SDL_RenderTexture(renderer_, &native_sdl_texture, &src_rect, &dest_rect);
	}


	SDLRenderer::~SDLRenderer() {
		if (renderer_)
			SDL_DestroyRenderer(renderer_);
	}
}
