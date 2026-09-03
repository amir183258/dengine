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
 * @file rectangle.hpp
 * 
 * @brief Defines the math::Rectangle type.
 */

#pragma once

#include <cassert>

namespace math {

	/**
	 * @struct Rectangle
	 * @brief Represents an axis-aligned rectangle.
	 *
	 * A rectangle is defined by its position and strictly positive dimensions.
	 *
	 * @headerfile core/math/rectangle.hpp
	 *
	 * @invariant w() > 0
	 * @invariant h() > 0
	 */
	struct Rectangle {
	private:
		float x_ {};
		float y_ {};
		float w_ {};
		float h_ {};
	public:
		/**
		 * @brief Default construction is not allowed.
		 *
		 * A rectangle must be created with an explicit position and valid,
		 * strictly positive dimensions.
		 */
		constexpr Rectangle() = delete;

		/**
		 * @brief Constructs a rectangle.
		 *
		 * @param x Horizontal position of rectangle.
		 * @param y Vertical position of the rectangle.
		 * @param width Width of the rectangle.
		 * @param height Height of the rectangle.
		 *
		 * @pre width > 0
		 * @pre height > 0
		 */
		constexpr Rectangle(float x, float y, float width, float height) noexcept:
			x_ {x}, y_ {y}, w_ {width}, h_ {height}
		{
			assert(w_ > 0.0f && "Rectangle width must be greater than 0");
			assert(h_ > 0.0f && "Rectangle height must be greater than 0");
		}

		/**
		 * @brief Returns the horizontal position.
		 *
		 * @return The x-coordinate of the rectangle.
		 */
		[[nodiscard]] inline constexpr float x() const noexcept {
			return x_;
		}
		
		/**
		 * @brief Returns the vertical position.
		 *
		 * @return The y-coordinate of the rectangle.
		 */
		[[nodiscard]] inline constexpr float y() const noexcept {
			return y_;
		}

		/**
		 * @brief Returns the width.
		 *
		 * @return The strictly positive width of the rectangle.
		 */
		[[nodiscard]] inline constexpr float w() const noexcept {
			return w_;
		}

		/**
		 * @brief Returns the height.
		 *
		 * @return The strictly positive height of the rectangle.
		 */
		[[nodiscard]] inline constexpr float h() const noexcept {
			return h_;
		}

		/**
		 * @brief Changes the position of the rectangle.
		 *
		 * @param x New horizontal position.
		 * @param y New vertical position.
		 */
		inline void set_position(float x, float y) noexcept {
			x_ = x;
			y_ = y;
		}

		/**
		 * @brief Changes the dimensions of the rectangle.
		 *
		 * @param width New width of the rectangle.
		 * @param height New height of the rectangle.
		 *
		 * @pre width > 0
		 * @pre height > 0
		 */
		inline void set_size(float width, float height) noexcept {
			assert(width > 0.0f && height > 0.0f);
			w_ = width;
			h_ = height;
		}
	};
} // namespace math
