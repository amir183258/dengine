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

#pragma once

/**
 * @file vector_2d.hpp
 *
 * @brief Defines the math::Vector2D type.
 */

namespace math {

	/**
	 * @struct Vector2D
	 * @brief Represents a 2d-vector.
	 *
	 * A 2d-vector is defined using its x and y position.
	 *
	 * @headerfile core/math/rectangle.hpp
	 */
	struct Vector2D {
		float x {};
		float y {};

		/**
		 * @brief Default constructor.
		 *
		 * Creates (0, 0) 2d-vector.
		 */
		constexpr Vector2D() = default;

		/**
		 * @brief Constructs a 2d-vector.
		 *
		 * @param x_ x position of the 2d-vector.
		 * @param y_ y position of the 2d-vector.
		 */
		constexpr Vector2D(float x_, float y_) noexcept:
			x {x_}, y {y_} {}

		/**
		 * @brief Returns the length of the 2d-vector.
		 *
		 * @return The euclidean length of the 2d-vector.
		 */
		float length() const noexcept;

		/**
		 * @brief Returns the squared length of the 2d-vector.
		 *
		 * @return The squared euclidean length of the 2d-vector.
		 */
		float length_squared() const noexcept;

		/**
		 * @brief Returns the normalized 2d-vector.
		 *
		 * @note If the 2d-vector's length is zero, it returns a zero vector (Vector2D {0.0f, 0.0f}).
		 *
		 * @return A new Vector2D with the same direction but a length of 1.
		 */
		Vector2D normalized() const noexcept;

		/**
		 * @brief Adds another 2d-vector to this 2d-vector component-wise.
		 *
		 * @param other The 2d-vector to add.
		 *
		 * @return Reference to this 2d-vector (*this).
		 */
		Vector2D& operator+=(const Vector2D& other) noexcept;

		/**
		 * @brief Sbtracts another 2d-vector from this 2d-vector component-wise.
		 *
		 * @param other The 2d-vector to subtract.
		 *
		 * @return Reference to this 2d-vector (*this).
		 */
		Vector2D& operator-=(const Vector2D& other) noexcept;

		/**
		 * @brief Multiplies this 2d-vector by a scalar value.
		 *
		 * @param s The scalar multiplier.
		 *
		 * @return Reference to this 2d-vector (*this).
		 */
		Vector2D& operator*=(const float s) noexcept;
	};

	// operators

	/**
	 * @brief Adds two 2d-vectors component-wise.
	 *
	 * @param a First 2d-vector.
	 * @param b Second 2d-vector.
	 *
	 * @return The component-wise sum of @p a and @p b.
	 */
	inline Vector2D operator+(const Vector2D &a, const Vector2D &b) noexcept {
		return {a.x + b.x, a.y + b.y};
	}

	/**
	 * @brief Subtracts the second 2d-vector from the first 2d-vector component-wise.
	 *
	 * @param a The 2d-vector to subtract from.
	 * @param b The vector to subtract.
	 *
	 * @return The component-wise difference of @p a and @p b.
	 */
	inline Vector2D operator-(const Vector2D &a, const Vector2D &b) noexcept {
		return {a.x - b.x, a.y - b.y};

	}

	/**
	 * @brief Multiplies a scalar to a 2d-vector.
	 *
	 * @param a The 2d-vector.
	 * @param s The scalar.
	 *
	 * @return The scaled 2d-vector.
	 */
	inline Vector2D operator*(const Vector2D &a, float s) noexcept {
		return {a.x * s, a.y * s};
	}

	/**
	 * @brief Multiplies a scalar to a 2d-vector.
	 *
	 * @param s The scalar.
	 * @param a The 2d-vector.
	 *
	 * @return The scaled 2d-vector.
	 */
	inline Vector2D operator*(float s, const Vector2D &a) noexcept {
		return {a.x * s, a.y * s};
	}

	/**
	 * @brief Returns the length of distance vector of 2 2d-vectors.
	 *
	 * @param a The first 2d-vector.
	 * @param b The second 2d-vector
	 *
	 * @return The distance length between @p a and @p b.
	 */
	inline float distance(const Vector2D &a, const Vector2D &b) noexcept {
		return (a - b).length();
	}

	/**
	 * @brief Returns the squared length of distance vector of 2 2d-vectors.
	 *
	 * @param a The first 2d-vector.
	 * @param b The second 2d-vector
	 *
	 * @return The distance squared length between @p a and @p b.
	 */
	inline float distance_squared(const Vector2D &a, const Vector2D &b) noexcept {
		return (a - b).length_squared();
	}
}
