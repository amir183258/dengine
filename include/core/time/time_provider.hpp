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
 * @file time_provider.hpp
 * 
 * @brief Defines the TimeProvider type.
 */

#pragma once

#include <cstdint>

namespace dengine {

	/**
	 * @class TimeProvider
	 * @brief Represents an abstract time provider.
	 *
	 * TimeProvider class can return current millisecond and
	 * it can sleep.
	 *
	 * @headerfile core/time/time_provider.hpp
	 */
	class TimeProvider {
	private:
	protected:
		/**
		 * @brief Default constructor.
		 *
		 * @note Protected to be used only by derived classes.
		 */
		TimeProvider() = default;
	public:
		// no copy and move for TimeProvider class.
		/**
		 * @brief Copy constructor deleted.
		 */
		TimeProvider(const TimeProvider&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		TimeProvider& operator=(const TimeProvider&) = delete;

		/**
		 * @brief Move Constructor deleted.
		 */
		TimeProvider(TimeProvider&&) = delete; 

		/**
		 * @brief Move assignment deleted.
		 */
		TimeProvider& operator=(TimeProvider&&) = delete;

		/**
		 * @brief Returns current millisecond.
		 *
		 * @return Current millisecond.
		 */
		virtual uint32_t now_ms() = 0;

		/**
		 * @brief Sleeps for a duration in millisecond.
		 *
		 * @param ms The duration of sleep in millisecond.
		 */
		virtual void sleep_ms(uint32_t ms) = 0;

		/**
		 * @brief The interface virtual defualt destructor.
		 */
		virtual ~TimeProvider() = default;
	};
}
