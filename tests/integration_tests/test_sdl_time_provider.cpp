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

#include <cstdint>
#include <gtest/gtest.h>

#include <core/time/sdl_time_provider.hpp>

TEST(SDLTimeProviderTest, NowAndSleep) {
	dengine::SDLTimeProvider t;

	uint32_t start = t.now_ms();
	t.sleep_ms(10);
	uint32_t end = t.now_ms();

	EXPECT_GE(end, start);
}
