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
 * @file fps_handler.hpp
 * 
 * @brief Defines the fps handler for the engine.
 */

#pragma once

#include <cstdint>

namespace dengine {
	class TimeProvider;

	/**
	 * @class FPSHandler
	 * @brief This class is used to manage FPS.
	 *
	 * This is a simple class to manage FPS in your game.
	 * It uses sleep to match your target FPS.
	 *
	 * @headerfile engine/fps_handler.hpp
	 */
	class FPSHandler {
	private:
		/**
		 * @brief The time provider for measuring the time.
		 */
		TimeProvider &time;

		/**
		 * @brief sets the beginning time.
		 */
		uint32_t frame_start;

		/**
		 * @brief Target FPS.
		 */
		uint32_t target_fps;

		/**
		 * @brief Frame time which is 1000 (ms) / target_fps.
		 */
		uint32_t frame_time;
	
	public:
		/**
		 * @brief Default constructor is deleted cause this class needs TimeProvider.
		 */
		FPSHandler() = delete;

		/**
		 * @brief Constructor using a TimeProvider reference.
		 *
		 * @param t TimeProvider reference.
		 */
		explicit FPSHandler(TimeProvider &t);

		/**
		 * @brief Constructor using a TimeProvider reference and target FPS.
		 *
		 * @param t TimeProvider reference.
		 * @param _target_fps Target Fps.
		 */
		explicit FPSHandler(TimeProvider &t, uint32_t _target_fps);

		/**
		 * @brief Call this function at the start of your frame loop.
		 */
		void begin_frame();

		/**
		 * @brief Call this function at the end of your frame loop.
		 */
		void end_frame();

		/**
		 * @brief Sets the target FPS.
		 *
		 * With this function you can change the target FPS.
		 *
		 * @param target The target FPS.
		 */
		void set_target_fps(uint32_t target);

		/**
		 * @brief Returns the target fps of this object.
		 *
		 * @return The target fps.
		 */
		[[nodiscard]] uint32_t get_target_fps();

		/**
		 * @brief The default destructor.
		 */
		~FPSHandler() = default;
	};
}
