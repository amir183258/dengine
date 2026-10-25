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
 * @file frame_clock.hpp
 * 
 * @brief Defines the frame clock for the engine.
 */

#pragma once

#include <cstdint>

namespace dengine {
	class TimeProvider;
}

namespace dengine {

	/**
	 * @class FrameClock
	 * @brief This class is used to manage frame times (for example in animations).
	 *
	 * @headerfile engine/frame_clock.hpp
	 */
	class FrameClock {
	private:
		/**
		 * @brief The time provider for the frame clock.
		 *
		 * @note The frame clock does not own the time provider.
		 */
		TimeProvider* time_provider_;

		/**
		 * @brief The last time of the frame clock.
		 *
		 * @note It uses time provider, so it is in milliseconds.
		 */
		uint32_t last_time_;

		/**
		 * @brief The delta time of the frame clock.
		 *
		 * @note It converts the milliseconds to decimal seconds.
		 */
		float delta_time_;
	public:
		/**
		 * @brief No default constructor.
		 */
		FrameClock() = delete;

		/**
		 * @brief The constructor needs a time provider to measure frame times.
		 *
		 * @param time_provider The time provider of the frame clock.
		 */
		explicit FrameClock(TimeProvider *time_provider);

		// no copy and move for FrameClock class.
		/**
		 * @brief Copy constructor deleted.
		 */
		FrameClock(const FrameClock&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		FrameClock& operator=(const FrameClock&) = delete;

		/**
		 * @brief Move Constructor deleted.
		 */
		FrameClock(FrameClock&&) = delete; 

		/**
		 * @brief Move assignment deleted.
		 */
		FrameClock& operator=(FrameClock&&) = delete;

		/**
		 * @brief Updates the frame clock using its time provider.
		 */
		void update();

		/**
		 * @brief Returns the delta time using the last update time.
		 */
		float get_delta_time() const;

		/**
		 * @brief The default destructor.
		 */
		~FrameClock() = default;
	};
}
