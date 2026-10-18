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
 * @file audio.hpp
 * 
 * @brief Defines the mixer for the engine.
 */

#pragma once

namespace dengine {

	/**
	 * @class Mixer
	 * @brief Represnets an abstract mixer.
	 *
	 * Mixers are used to mix different tracks to
	 * generate audio.
	 *
	 * @headerfile core/audio/mixer.hpp
	 */
	class Mixer {
	private:
	protected:
		/**
		 * @brief Default constructor.
		 *
		 * @note Protected to be used only by derived classes.
		 */
		Mixer() = default;
	public:
		// no copy and move for Mixer class.
		/**
		 * @brief Copy constructor deleted.
		 */
		Mixer(const Mixer&) = delete;

		/**
		 * @breif Copy assignment deleted.
		 */
		Mixer& operator=(const Mixer&) = delete;

		/**
		 * @breif Move constructor deleted.
		 */
		Mixer(Mixer&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		Mixer& operator=(Mixer&&) = delete;

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~Mixer() = default;
	};
}
