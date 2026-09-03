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

#include <cstdint>

struct Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a = 255;

	bool operator==(const Color&) const = default;
};

namespace Colors {
	inline constexpr Color Black {0, 0, 0};
	inline constexpr Color White {255, 255, 255};

	inline constexpr Color Red {255, 0, 0};
	inline constexpr Color Green {0, 255, 0};
	inline constexpr Color Blue {0, 0, 255};

	inline constexpr Color Yellow {255, 255, 0};
	inline constexpr Color Cyan {0, 255, 255};
	inline constexpr Color Magenta {255, 0, 255};
}
