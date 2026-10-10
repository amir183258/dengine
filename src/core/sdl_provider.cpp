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

#include <core/sdl_provider.hpp>
#include <core/window/init.hpp>
#include <core/window/sdl_init.hpp>
#include <core/window/window.hpp>
#include <core/window/sdl_window.hpp>
#include <core/graphics/renderer.hpp>
#include <core/graphics/sdl_renderer.hpp>
#include <core/graphics/texture.hpp>
#include <core/graphics/sdl_texture.hpp>
#include <core/time/time_provider.hpp>
#include <core/time/sdl_time_provider.hpp>

namespace dengine {
	std::unique_ptr<Init> SDLProvider::create_init() {
		return std::make_unique<SDLInit>();
	}

	std::unique_ptr<Window> SDLProvider::create_window(const std::string &title,
			uint32_t width, uint32_t height)
	{
		std::unique_ptr<SDLWindow> window_ptr =
			std::make_unique<SDLWindow>(title, width, height);

		if (window_ptr->is_valid())
			return window_ptr;
		else
			return nullptr;
	}

	std::unique_ptr<Renderer> SDLProvider::create_renderer(Window &window) {
		SDLWindow &sdl_window = static_cast<SDLWindow&>(window);
		std::unique_ptr<SDLRenderer> renderer_ptr =
			std::make_unique<SDLRenderer>(sdl_window);

		if (renderer_ptr->is_valid())
			return renderer_ptr;
		else
			return nullptr;
	}


	std::unique_ptr<Texture> SDLProvider::create_texture(Renderer &renderer,
			const std::string &path)
	{
		SDLRenderer &sdl_renderer = static_cast<SDLRenderer&>(renderer);
		std::unique_ptr<SDLTexture> texture_ptr =
			std::make_unique<SDLTexture>(sdl_renderer, path);

		if (texture_ptr->is_valid())
			return texture_ptr;
		else
			return nullptr;
	}

	std::unique_ptr<TimeProvider> SDLProvider::create_time_provider() {
		return std::make_unique<SDLTimeProvider>();
	}
}
