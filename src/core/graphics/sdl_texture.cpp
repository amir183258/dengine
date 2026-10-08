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
#include <SDL3_image/SDL_image.h>

#include <core/graphics/sdl_texture.hpp>
#include <core/graphics/sdl_renderer.hpp>

namespace dengine {
	SDLTexture::SDLTexture():
		texture_ {nullptr},
		width_ {0.0f},
		height_ {0.0f}
	{
	}

	SDLTexture::SDLTexture(SDLRenderer &renderer, const std::string &path):
		texture_ {nullptr},
		width_ {0.0f},
		height_ {0.0f}
	{
		texture_ = IMG_LoadTexture(&renderer.get_sdl_renderer_handle(),
				path.c_str());

		if (texture_)
			SDL_GetTextureSize(texture_, &width_, &height_);
	}

	SDLTexture::SDLTexture(SDLTexture&& other) noexcept:
		texture_ {other.texture_},
		width_ {other.width_},
		height_ {other.height_}
	{
		other.texture_ = nullptr;
		other.width_ = 0.0f;
		other.height_ = 0.0f;
	}

	SDLTexture& SDLTexture::operator=(SDLTexture&& other) noexcept {
		if (this != &other) {
			if (texture_ != nullptr)
				SDL_DestroyTexture(texture_);

			texture_ = other.texture_;
			width_ = other.width_;
			height_ = other.height_;

			other.texture_ = nullptr;
			other.width_ = 0.0f;
			other.height_ = 0.0f;
		}

		return *this;
	}

	uint32_t SDLTexture::width() const {
		return static_cast<uint32_t>(width_);
	}

	uint32_t SDLTexture::height() const {
		return static_cast<uint32_t>(height_);
	}

	SDLTexture::~SDLTexture() {
		if (texture_)
			SDL_DestroyTexture(texture_);
	}
}
