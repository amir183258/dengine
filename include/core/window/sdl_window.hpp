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

/**
 * @file sdl_window.hpp
 * 
 * @brief Defines the SDLWindow which implements Window.
 */

#pragma once

#include <string>
#include <cstdint>

#include <core/window/window.hpp>

// this is the native window in SDL3.
struct SDL_Window;

namespace dengine {

	/**
	 * @class SDLWindow
	 * @brief Represents a SDL window.
	 *
	 * This class manages the window for engine using
	 * SDL_Window struct in SDL3.
	 *
	 * @headerfile core/window/sdl_window.hpp
	 */
	class SDLWindow : public Window {
	private:
		/**
		 * @brief The underlying SDL window handle.
		 */
		SDL_Window *window;

	public:
		/**
		 * @brief Defualt constructor.
		 *
		 * Creates a 640 x 480 window with the title "Dengine Game".
		 *
		 * @warning SDLInit must be started before creating window.
		 */
		SDLWindow();

		/**
		 * @brief Constructor which creates a window.
		 *
		 * @param title The title (name) of the window.
		 * @param width The initial width of the window.
		 * @param height The initial height of the window.
		 *
		 * @warning SDLInit must be started before createing window.
		 */
		SDLWindow(std::string title, uint32_t width, uint32_t height);

		// no copy for window class
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLWindow(const SDLWindow&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		SDLWindow& operator=(const SDLWindow&) = delete;

		// can move
		/**
		 * @brief Move constructor.
		 *
		 * @note noexcept for using in std containers.
		 */
		SDLWindow(SDLWindow&&) noexcept;

		/**
		 * @brief Move assignment.
		 *
		 * @note noexcept for using in std containers.
		 */
		SDLWindow& operator=(SDLWindow&&) noexcept;

		/**
		 * @brief Checks if the sdl window is valid.
		 *
		 * @return True if valid and false if not valid.
		 */
		[[nodiscard]] bool is_valid() const { return window != nullptr; }

		/**
		 * @brief Returns the current width of the window.
		 *
		 * @return The current width of the window.
		 */
		uint32_t get_width() const override;

		/**
		 * @brief Returns the current height of the window.
		 *
		 * @return The current height of the window.
		 */
		uint32_t get_height() const override;

		/**
		 * @brief Returns the native SDL window handle.
		 *
		 * @return The current SDL window or nullptr.
		 */
		[[nodiscard]] SDL_Window& get_sdl_window_handle() const;

		/**
		 * @brief The virtual destructor which overrides.
		 */
		~SDLWindow() override;
	};
}
