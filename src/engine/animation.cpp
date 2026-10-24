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

#include <string>
#include <cstdint>
#include <memory>

#include <engine/animation.hpp>
#include <core/graphics/texture.hpp>
#include <core/math/rectangle.hpp>

namespace dengine {
	Animation::Animation(Texture *texture,
			uint32_t frames_count,
			float frame_duration,
			bool loop):
		texture_ {texture},
		frames_count_ {frames_count},
		frame_duration_ {frame_duration},
		loop_ {loop}
	{
		elapsed_time_ = 0.0f;
		finished_ = false;
		current_frame_ = 0;

		frame_width_ = texture->width() / frames_count_;
	}

	void Animation::update(float delta_time) {
		elapsed_time_ += delta_time;

		while (elapsed_time_ >= frame_duration_) {
			elapsed_time_ -= frame_duration_;
			++current_frame_;

			if (current_frame_ >= frames_count_)
				if (loop_)
					current_frame_ = 0;
				else {
					current_frame_ = frames_count_ - 1;
					finished_ = true;
					break;
				}
		}
	}

	bool Animation::is_finished() const {
		return finished_;
	}

	void Animation::reset() {
		elapsed_time_ = 0;
		current_frame_ = 0;
		finished_ = false;
	}

	uint32_t Animation::width() {
		return frame_width_;
	}

	uint32_t Animation::height() {
		return texture_->height();
	}

	FrameInfo Animation::get_current_frame_info() const {
		math::Rectangle render_rect {
			(float)current_frame_ * frame_width_,
			0.0f,
			(float)frame_width_,
			(float)texture_->height()
		};

		FrameInfo info {
			texture_,
			render_rect
		};

		return info;
	}

	void Animation::set_loop(bool do_loop) {
		loop_ = do_loop;
	}
}
