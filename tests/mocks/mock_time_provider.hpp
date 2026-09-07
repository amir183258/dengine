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
 * @file mock_time_provider.hpp
 * 
 * @brief Defines the TimeProvider type.
 */

#pragma once

#include <cstdint>

#include <core/time/time_provider.hpp>

/**
 * @brief Mock implementation of TimeProvider for unit testing.
 *
 * Advances time manually via sleep_ms() instead of system clock.
 */
namespace dengine::tests {
	class MockTimeProvider : public TimeProvider {
	private:
	public:
		uint32_t current = 0; // simulated time in millisecond

		uint32_t now_ms() override { return current; }
		void sleep_ms(uint32_t ms) override { current += ms; }
	};
}
