#include <cmath>
#include <core/math/vector_2d.hpp>

float math::Vector2D::length() const noexcept {
	return std::sqrt(x * x + y * y);
}

float math::Vector2D::length_squared() const noexcept {
	return x * x + y * y;
}

math::Vector2D math::Vector2D::normalized() const noexcept {
	float len = length();
	return (len > 0.0f) ? math::Vector2D {x / len, y / len}: math::Vector2D {};
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
