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

#include <gtest/gtest.h>

#include <engine/frame_clock.hpp>
#include <mock_time_provider.hpp>

TEST(FrameClockTest, UpdateClock) {
	dengine::tests::MockTimeProvider fake_time;
	dengine::FrameClock frame_clock {&fake_time};

	// wait 13 ms
	fake_time.sleep_ms(13);

	frame_clock.update();

	SUCCEED();
}

TEST(FrameClockTest, GetDeltaTime) {
	dengine::tests::MockTimeProvider fake_time;
	dengine::FrameClock frame_clock {&fake_time};

	// wait 17 ms
	fake_time.sleep_ms(17);

	frame_clock.update();

	EXPECT_EQ(frame_clock.get_delta_time(), 17 / 1000.0f);

	SUCCEED();
}
