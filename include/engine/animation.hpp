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
 * @file animation.hpp
 * 
 * @brief Defines the Animation class for the dengine.
 */

#pragma once

#include <string>
#include <cstdint>
#include <memory>

#include <core/math/rectangle.hpp>

namespace dengine {
	class Texture;
}

namespace dengine {

	/**
	 * @struct FrameInfo
	 *
	 * This structure holds frame information of an animation.
	 *
	 * @headerfile engine/animation.hpp
	 */
	struct FrameInfo {
		const Texture* texture;
		math::Rectangle rect;
	};

	/**
	 * @class Animation
	 *
	 * This class is used to create animations using
	 * textures.
	 *
	 * @headerfile engine/animation.hpp
	 */
	class Animation {
	private:
		/**
		 * @brief The texture of the animation.
		 *
		 * @note The animation does not own the texture.
		 */
		const Texture* const texture_;

		/**
		 * @brief The number of frames in the texture.
		 */
		uint32_t frames_count_;

		/**
		 * @brief The duration of eachframe.
		 *
		 * @note This duration is in seconds.
		 */
		float frame_duration_;

		/**
		 * @brief This is the elapsed time from the last frame.
		 */
		float elapsed_time_;

		/**
		 * @brief The current frame number.
		 *
		 * @note Starts from 0.
		 */
		uint32_t current_frame_;

		/**
		 * @brief The width of each frame in the texture.
		 */
		uint32_t frame_width_;

		/**
		 * @brief Shows animation is loop or not.
		 */
		bool loop_;

		/**
		 * @brief Shows animation is finished or not.
		 */
		bool finished_;
	public:
		/**
		 * @brief No default constructor.
		 */
		Animation() = delete;

		/**
		 * @brief Constructor creates the required texture and animation.
		 *
		 * @param texture The texture which is required for an animation.
		 * @param frames_count The nubmber of frames count in the texture.
		 * @param frame_duration The duration of each frame in seconds.
		 * @param loop Loop animation or not.
		 */
		Animation(Texture *texture,
				uint32_t frames_count,
				float frame_duration,
				bool loop = true);

		// no copy and move for Animation class.
		/**
		 * @brief Copy constructor deleted.
		 */
		Animation(const Animation&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		Animation& operator=(const Animation&) = delete;

		/**
		 * @brief Move Constructor deleted.
		 */
		Animation(Animation&&) = delete; 

		/**
		 * @brief Move assignment deleted.
		 */
		Animation& operator=(Animation&&) = delete;

		/**
		 * @brief Updates the state of the animation.
		 *
		 * @todo Should this function use a while loop?
		 */
		void update(float delta_time);

		/**
		 * @brief Checks if the animation is valid or not.
		 *
		 * @return True if the animation is valid, otherwise flase.
		 */
		[[nodiscard]] bool is_valid() { return texture_ != nullptr; }

		/**
		 * @brief Checks if the animation is finished or not.
		 *
		 * @return True if it is finished, otherwise false.
		 */
		[[nodiscard]] bool is_finished() const;

		/**
		 * @breif Resets the animation to the initial state.
		 */
		void reset();

		/**
		 * @brief The width of the animation.
		 *
		 * @note It is the width of each frame.
		 */
		[[nodiscard]] uint32_t width();

		/**
		 * @brief The height of the animation.
		 */
		[[nodiscard]] uint32_t height();

		/**
		 * @brief Returns the inforamtion of the frame to be rendererd.
		 *
		 * @return FrameInfo The information of the animation frame.
		 */
		[[nodiscard]] FrameInfo get_current_frame_info() const;

		/**
		 * @brief Change the loop behavior of the animation.
		 *
		 * @param do_loop True if animation loops, otherwise false.
		 */
		void set_loop(bool do_loop);

		/**
		 * @brief The default destructor.
		 */
		~Animation() = default;
	};
}
