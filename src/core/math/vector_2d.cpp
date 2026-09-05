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

#include <cmath>
#include <core/math/vector_2d.hpp>

namespace dengine {
	float math::Vector2D::length() const noexcept {
		return std::sqrt(x * x + y * y);
	}

	float math::Vector2D::length_squared() const noexcept {
		return x * x + y * y;
	}

	math::Vector2D math::Vector2D::normalized() const noexcept {
		float len = length();
		return (len > 0.0f) ? dengine::math::Vector2D {x / len, y / len}: dengine::math::Vector2D {};
	}

	math::Vector2D& math::Vector2D::operator+=(const math::Vector2D &other) noexcept {
		x += other.x;
		y += other.y;
		return *this;
	}

	math::Vector2D& math::Vector2D::operator-=(const math::Vector2D &other) noexcept {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	math::Vector2D& math::Vector2D::operator*=(const float s) noexcept {
		x *= s;
		y *= s;
		return *this;
	}
}
