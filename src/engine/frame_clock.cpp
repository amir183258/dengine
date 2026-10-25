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

#include <engine/frame_clock.hpp>
#include <core/time/time_provider.hpp>

namespace dengine {
	FrameClock::FrameClock(TimeProvider *time_provider):
		time_provider_ {time_provider},
		last_time_ {0},
		delta_time_ {0}
	{
		last_time_ = time_provider_->now_ms();
	}

	void FrameClock::update() {
		uint32_t current = time_provider_->now_ms();
		uint32_t diff = current - last_time_;
		last_time_ = current;

		delta_time_ = diff / 1000.0f; // seconds
	}

	float FrameClock::get_delta_time() const {
		return delta_time_;
	}
}
