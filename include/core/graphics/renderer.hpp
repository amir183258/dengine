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
 * @file renderer.hpp
 *
 * @brief Defines the Renderer which renders on window.
 */

#pragma once

#include <string>

#include <core/graphics/color.hpp>
#include <core/math/vector_2d.hpp>
#include <core/math/rectangle.hpp>

namespace dengine {
	class Window;
	class Texture;
}

namespace dengine {

	/**
	 * @class Renderer
	 * @brief Represents renderer abstract class.
	 *
	 * This class manages drawing different objects
	 * on the windows.
	 *
	 * @headerfile core/graphics/renderer.hpp
	 */
	class Renderer {
	private:
	protected:
		/**
		 * @brief Default constructor.
		 */
		Renderer() = default;
	public:
		// no copy and move for renderer class.
		/**
		 * @brief Copy constructor deleted.
		 */
		Renderer(const Renderer&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		Renderer& operator=(const Renderer&) = delete;

		/**
		 * @brief Move constructor delete.
		 */
		Renderer(Renderer&&) = delete;

		/**
		 * @brief Move assignment delete.
		 */
		Renderer& operator=(Renderer&&) = delete;

		/**
		 * @brief Clears the window.
		 */
		virtual void clear() = 0;

		/**
		 * @brief Clears the window using a color.
		 *
		 * @param color The color for clearing the window.
		 */
		inline void clear(const Color &color) {
			set_draw_color(color);
			clear();
		}

		/**
		 * @brief Update the screen with any rendering performed since
		 * the previous call.
		 */
		virtual void present() = 0;

		/**
		 * @breif Sets draw color for the renderer.
		 *
		 * @param color The new color to be set.
		 */
		virtual void set_draw_color(const Color &color) = 0;

		/**
		 * @brief Draws a point on the screen.
		 *
		 * @param x The x position of the point.
		 * @param y The y position of the point.
		 */
		virtual void draw_point(float x, float y) = 0;

		/**
		 * @brief Draws a point on the screen using Vector2D.
		 *
		 * @param point The point using Vector2D.
		 */
		inline void draw_point(const math::Vector2D &point) {
			draw_point(point.x, point.y);
		}

		/**
		 * @brief Draws a line on the screen.
		 *
		 * @param x1 The x position of the start point of the line.
		 * @param y1 The y position of the start point of the line.
		 * @param x2 The x position of the end point of the line.
		 * @param y2 The y position of the end point of the line.
		 */
		virtual void draw_line(float x1, float y1, float x2, float y2) = 0;

		/**
		 * @brief Draws a line on the screen using Vector2D.
		 *
		 * @param start_point The start point of the line.
		 * @param end_point The end point of the line.
		 */
		inline void draw_line(const math::Vector2D &start_point,
				const math::Vector2D &end_point)
		{
			draw_line(start_point.x, start_point.y, end_point.x,
					end_point.y);
		}

		/**
		 * @brief Draws a rectangle on the screen.
		 *
		 * @param x The x position of the top-left corner of the rectanlge.
		 * @param y The y position of the top-left corner of the rectanlge.
		 * @param w The width of the rectangle.
		 * @param h The height of the rectangle.
		 */
		virtual void draw_rect(float x, float y, float w, float h) = 0;

		/**
		 * @brief Draws a rectangle on the screen using Rectangle.
		 *
		 * @param rect The rectangle using Rectangle class.
		 */
		inline void draw_rect(const math::Rectangle &rect) {
			draw_rect(rect.x(), rect.y(), rect.w(), rect.h());
		}

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
		virtual void fill_rect(float x, float y, float w, float h) = 0;

		/**
		 * @brief Draws a filled rectangle on the screen using Rectangle.
		 *
		 * @param rect The rectangle using Rectangle struct.
		 */
		inline void fill_rect(const math::Rectangle &rect) {
			fill_rect(rect.x(), rect.y(), rect.w(), rect.h());
		}

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
		virtual void draw_texture(Texture &texture, float src_x, float src_y,
				float src_w, float src_h, float dest_x, float dest_y,
				float dest_w, float dest_h) = 0;

		/**
		 * @brief Draws a texture on the screen.
		 *
		 * It uses default source configuration and only gets the
		 * destination position.
		 *
		 * @param texture The Texture to be rendered on the screen.
		 * @param x The destination x position.
		 * @param y The destination y position.
		 */
		inline void draw_texture(Texture &texture, float x, float y) {
			draw_texture(texture, 0, 0, 0, 0, x, y, 0, 0);
		}

		/**
		 * @brief Draws a texture on the screen.
		 *
		 * This function uses Rectangle to draw a texture on the screen.
		 *
		 * @param texture The Texture to be rendered on the screen.
		 * @param src_rect The source rectangle.
		 * @param dest_rect The destination rectangle.
		 */
		inline void draw_texture(Texture &texture, const math::Rectangle &src_rect,
				const math::Rectangle &dest_rect)
		{
			draw_texture(texture, src_rect.x(), src_rect.y(), src_rect.w(),
					src_rect.h(), dest_rect.x(), dest_rect.y(),
					dest_rect.w(), dest_rect.h());
		}

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~Renderer() = default;
	};
}
