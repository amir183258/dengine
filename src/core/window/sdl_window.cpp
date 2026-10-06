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

#include <SDL3/SDL.h>

#include <core/window/sdl_window.hpp>

namespace dengine {
	SDLWindow::SDLWindow(): SDLWindow("Dengine Game", 640, 480)
	{
	}

	SDLWindow::SDLWindow(std::string title, uint32_t width, uint32_t height):
		window {nullptr}
       	{
		window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_RESIZABLE);
	}

	SDLWindow::SDLWindow(SDLWindow&& other) noexcept:
		window {other.window}
	{
		other.window = nullptr;
	}

	SDLWindow& SDLWindow::operator=(SDLWindow&& other) noexcept {
		if (this != &other) {
			if (window != nullptr)
				SDL_DestroyWindow(window);

			window = other.window;

			other.window = nullptr;
		}

		return *this;
	}

	uint32_t SDLWindow::get_width() const {
		if (!window)
			return 0;

		int w, h;
		SDL_GetWindowSize(window, &w, &h);
		return static_cast<uint32_t>(w);
	}

	uint32_t SDLWindow::get_height() const {
		if (!window)
			return 0;

		int w, h;
		SDL_GetWindowSize(window, &w, &h);
		return static_cast<uint32_t>(h);
	}

	SDL_Window& SDLWindow::get_sdl_window_handle() const {
		return *window;
	}

	SDLWindow::~SDLWindow() {
		if (window)
			SDL_DestroyWindow(window);
	}
}
