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
 * @file window.hpp
 * 
 * @brief Defines the window for the engine.
 */

#pragma once

#include <cstdint>

namespace dengine {

	/**
	 * @class Window
	 * @brief Represents an abstract window.
	 *
	 * Window can be the main window of the game. Moreover,
	 * there can be several windows, so it is not singleton.
	 *
	 * @headerfile core/window/window.hpp
	 */
	class Window {
	private:
	protected:
		/**
		 * @brief Default constructor.
		 *
		 * @note Protected to be used only by derived classes.
		 */
		Window() = default;
	public:
		// no copy and move for Window class.
		/**
		 * @brief Copy constructor deleted.
		 */
		Window(const Window&) = delete;

		/**
		 * @breif Copy assignment deleted.
		 */
		Window& operator=(const Window&) = delete;

		/**
		 * @breif Move constructor deleted.
		 */
		Window(Window&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		Window& operator=(Window&&) = delete;

		/**
		 * @brief Returns the width of the window.
		 *
		 * @return The width of this window.
		 */
		virtual uint32_t get_width() const = 0;

		/**
		 * @brief Returns the height of the window.
		 *
		 * @return The height of this window.
		 */
		virtual uint32_t get_height() const = 0;

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~Window() = default;
	};
}
