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
 * @file sdl_renderer.hpp
 *
 * @brief Implements Renderer abstract class.
 */

#pragma once

#include <core/graphics/renderer.hpp>

namespace dengine {
	class SDLWindow;
}
struct SDL_Renderer;

namespace dengine {

	/**
	 * @class SDLRenderer
	 * @brief Represents a SDL renderer.
	 *
	 * This class is used to render objects on a window
	 * using SDL_Renderer struct in SDL3.
	 *
	 * @headerfile core/graphics/sdl_renderer.hpp
	 */
	class SDLRenderer : public Renderer {
	private:
		/**
		 * @brief The underlying SDL renderer handle.
		 */
		SDL_Renderer *renderer_;
	public:
		/**
		 * @brief Deleted default constructor.
		 *
		 * SDLRenderer needs SDLWindow to work, so there is no
		 * default constructor.
		 */
		SDLRenderer() = delete;

		/**
		 * @brief Constructor using SDLWindow.
		 *
		 * There must be a window for rendering objects.
		 *
		 * @param window The window to render.
		 */
		explicit SDLRenderer(SDLWindow &window);

		// no copy and move for renderer class
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLRenderer(const SDLRenderer&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		SDLRenderer& operator=(const SDLRenderer&) = delete;

		/**
		 * @brief Move constructor deleted.
		 */
		SDLRenderer(SDLRenderer&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 *
		 * @note noexcept for using in std containers.
		 */
		SDLRenderer& operator=(SDLRenderer&&) = delete;

		/**
		 * @brief Checks if renderer is valid.
		 *
		 * @return True if renderer is valid, otherwise false.
		 */
		[[nodiscard]] bool is_valid() const { return renderer_ != nullptr; }

		/**
		 * @brief Clears window.
		 */
		void clear() override;

		/**
		 * @brief The destructor of SDLRenderer.
		 */
		~SDLRenderer();
	};
}
