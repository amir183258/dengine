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
 * @file sdl_init.hpp
 * 
 * @brief Defines the SDLInit class for the engine.
 */

#pragma once

#include <core/window/init.hpp>

namespace dengine {

	
	/**
	 * @calss SDLInit
	 * @brief Represents SDL3 initialization calss.
	 *
	 * This class implements Init class with SDL3.
	 *
	 * @headerfile core/window/sdl_init.hpp
	 */
	class SDLInit : public Init {
	private:
		static bool initialized;
	public:
		/**
		 * @brief Default contructor.
		 */
		SDLInit() = default;

		/**
		 * @brief Initializes SDL3 needed subsystems.
		 *
		 * @return True if successful, false otherwise.
		 *
		 * @todo Maybe this should get inputs for desired subsystems.
		 */
		[[nodiscard]] bool initialize() override;

		/**
		 * @brief Uninitialize SDL3 subsystems.
		 */
		void shutdown() override;

		/**
		 * @brief Checks if SDL3 is initialized or not.
		 *
		 * @return True if initialized, otherwise false.
		 */
		[[nodiscard]] bool is_initialized() const override;

		/**
		 * @brief The destructor calls shutdown.
		 */
		~SDLInit();
	};
}
