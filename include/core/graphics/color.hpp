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
 * @file color.hpp
 *
 * @brief Defines the general Color type.
 */

#pragma once

#include <cstdint>

/**
 * @struct Color
 * @brief Represents rgba color.
 *
 * A color is defined by its components which are red,
 * green, blue and alpha.
 *
 * @headerfile core/graphics/color.hpp
 */
struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a = 255;

	constexpr bool operator==(const Color&) const = default;
};

/**
 * @namespace Colors
 *
 * @brief A set of predefined, standard colors.
 *
 * These values are computed at compile-time (constexpr) and can be used
 * anywhere a Color is expected, without any runtime overhead.
 */
namespace Colors {
	/** @brief Pure black. */
	inline constexpr Color Black {0, 0, 0};
	/** @brief Pure white. */
	inline constexpr Color White {255, 255, 255};

	/** @brief Pure red. */
	inline constexpr Color Red {255, 0, 0};
	/** @brief Pure green. */
	inline constexpr Color Green {0, 255, 0};
	/** @brief Pure blue. */
	inline constexpr Color Blue {0, 0, 255};

	/** @brief A mix of red and green. */
	inline constexpr Color Yellow {255, 255, 0};
	/** @brief A mix of green and blue . */
	inline constexpr Color Cyan {0, 255, 255};
	/** @brief A mix of red and blue . */
	inline constexpr Color Magenta {255, 0, 255};
}
