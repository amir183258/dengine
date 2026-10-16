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

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <core/graphics/sdl_text_maker.hpp>
#include <core/graphics/sdl_renderer.hpp>
#include <core/graphics/color.hpp>
#include <core/graphics/sdl_texture.hpp>

namespace dengine {
	SDLTextMaker::SDLTextMaker(SDLRenderer* renderer,
			const std::string& font_path, int size):
		renderer_ {renderer},
		text_color_ {Colors::Black}
	{
		font_ = TTF_OpenFont(font_path.c_str(), size);
	}

	void SDLTextMaker::set_color(const Color &font_color) {
		text_color_ = font_color;
	}

	std::unique_ptr<Texture> SDLTextMaker::make_text(const std::string &text) {
		SDL_Color text_color = {text_color_.r,
					text_color_.g,
					text_color_.b,
					text_color_.a};

		SDL_Surface *temp_surface = TTF_RenderText_Solid(font_, text.c_str(), 0,
				text_color);

		SDL_Texture *text_texture =
			SDL_CreateTextureFromSurface(&renderer_->get_sdl_renderer_handle(),
			temp_surface);

		// texture is the owner
		std::unique_ptr<SDLTexture> texture =
			std::make_unique<SDLTexture>(text_texture);

		SDL_DestroySurface(temp_surface);

		return texture;
	}

	SDLTextMaker::~SDLTextMaker() {
		TTF_CloseFont(font_);
	}
}
