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
 * @file init.hpp
 * 
 * @brief Defines the Init class for the engine.
 */

#pragma once

namespace dengine {

	/**
	 * @class Init
	 * @brief This class is used to initialize the engine.
	 *
	 * The Init class makes the engine ready to use and it
	 * has to be the first class which runs at the beginning of
	 * the code.
	 *
	 * @headerfile core/window/init.hpp
	 */
	class Init {
	private:
	public:
		/**
		 * @brief Initializes the specific subsystem (e.g., SDL3).
		 * @return true if successful, false otherwise.
		 */
		virtual bool initialize() = 0;

		/**
		 * @brief Cleans up resources and shuts down the subsystem.
		 */
		virtual void shutdown() = 0;

		/**
		 * @brief Checks if the subsystem is currently active.
		 */
		virtual is_initialized() const = 0;

		/**
		 * @brief The interface virtual default constructor.
		 */
		virtual ~Init() = default;
	};
}
