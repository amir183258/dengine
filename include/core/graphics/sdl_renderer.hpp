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
		 * @brief Returns the native SDL renderer handle.
		 *
		 * @return The current SDL renderer or nullptr.
		 */
		[[nodiscard]] SDL_Renderer& get_sdl_renderer_handle() const;

		/**
		 * @brief Clears window.
		 *
		 * @note The clear color can be changed.
		 */
		void clear() override;

		/**
		 * @brief Update the screen with any rendering performed since
		 * the previous call.
		 */
		void present() override;

		/**
		 * @breif Sets draw color for the renderer.
		 *
		 * @param color The new color to be set.
		 */
		void set_draw_color(const Color &color) override;

		/**
		 * @brief Draws a point on the screen.
		 *
		 * @param x The x position of the point.
		 * @param y The y position of the point.
		 */
		void draw_point(float x, float y) override;

		/**
		 * @brief Draws a line on the screen.
		 *
		 * @param x1 The x position of the start point of the line.
		 * @param y1 The y position of the start point of the line.
		 * @param x2 The x position of the end point of the line.
		 * @param y2 The y position of the end point of the line.
		 */
		void draw_line(float x1, float y1, float x2, float y2) override;

		/**
		 * @brief Draws a rectangle on the screen.
		 *
		 * @param x The x position of the top-left corner of the rectanlge.
		 * @param y The y position of the top-left corner of the rectanlge.
		 * @param w The width of the rectangle.
		 * @param h The height of the rectangle.
		 */
		void draw_rect(float x, float y, float w, float h) override;

		/**
		 * @brief Draws a filled rectangle on the screen.
		 *
		 * @param x The x position of the top-left corner of the rectanlge.
		 * @param y The y position of the top-left corner of the rectanlge.
		 * @param w The width of the rectangle.
		 * @param h The height of the rectangle.
		 *
		 * @note You have to use set_draw_color() to change the color.
		 */
		void fill_rect(float x, float y, float w, float h) override;

		/**
		 * @brief Draws a texture on the screen.
		 *
		 * @param texture The Texture to be rendererd on the screen.
		 * @param src_x The source x position.
		 * @param src_y The source y position.
		 * @param src_w The source width.
		 * @param src_h The source height.
		 * @param dest_x The destination x position.
		 * @param dest_y The destination y position.
		 * @param dest_w The destination width;
		 * @param dest_h The destination height;
		 */
		void draw_texture(Texture &texture, float src_x, float src_y,
				float src_w, float src_h, float dest_x, float dest_y,
				float dest_w, float dest_h) override;
		/**
		 * @brief The destructor of SDLRenderer.
		 */
		~SDLRenderer();
	};
}
