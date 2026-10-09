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
 * @file sdl_time_provider.hpp
 * 
 * @brief Defines the SDLTimeProvider type.
 */

#pragma once

#include <cstdint>

#include <core/time/time_provider.hpp>

namespace dengine {

	/**
	 * @class SDLTimeProvider
	 * @brief SDL implementation of TimeProvider.
	 *
	 * This class uses SDL to manage time in millisecond.
	 *
	 * @headerfile core/time/sdl_time_provider.hpp"
	 */
	class SDLTimeProvider : public TimeProvider {
	private:
	public:
		/**
		 * @brief Default constructor.
		 */
		SDLTimeProvider() = default;

		// no copy and move for SDLTimeProvider class.
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLTimeProvider(const SDLTimeProvider&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		SDLTimeProvider& operator=(const SDLTimeProvider&) = delete;

		/**
		 * @brief Move Constructor deleted.
		 */
		SDLTimeProvider(SDLTimeProvider&&) = delete; 

		/**
		 * @brief Move assignment deleted.
		 */
		SDLTimeProvider& operator=(SDLTimeProvider&&) = delete;

		/**
		 * @brief Returns current millisecond.
		 *
		 * @return Current millisecond.
		 */
		uint32_t now_ms() override;

		/**
		 * @brief Sleeps for a duration in millisecond.
		 *
		 * @param ms The duration of sleep in millisecond.
		 */
		void sleep_ms(uint32_t) override;

		/**
		 * The destructor is default.
		 */
		~SDLTimeProvider() override = default;
	};
}
