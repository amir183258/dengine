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

#include <engine/fps_handler.hpp>
#include <core/time/time_provider.hpp>

namespace dengine {
	FPSHandler::FPSHandler(TimeProvider &t):
		time {t}, target_fps {60},
		frame_time {1000 / 60},
		frame_start {0}
	{
	}

	FPSHandler::FPSHandler(TimeProvider &t, uint32_t _target_fps):
		time {t}, target_fps {_target_fps},
		     frame_time { (uint32_t)(1000 / _target_fps)},
		     frame_start {0}
	{
	}

	void FPSHandler::begin_frame() {
		frame_start = time.now_ms();
	}

	void FPSHandler::end_frame() {
		uint32_t elapsed = time.now_ms() - frame_start;

		if (elapsed < frame_time)
			time.sleep_ms(frame_time - elapsed);
	}

	void FPSHandler::set_target_fps(uint32_t target) {
		target_fps = target;
		frame_time = 1000 / target_fps;
	}

	uint32_t FPSHandler::get_target_fps() {
		return target_fps;
	}
}
