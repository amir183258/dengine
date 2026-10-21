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
 * @brief Defines the audio for the engine.
 */

#pragma once

namespace dengine {

	/**
	 * @class Audio
	 * @brief Represents an abstract audio.
	 *
	 * Audio is used to read audio files into the
	 * RAM and can be used in tracks for Mixer.
	 *
	 * @headerfile core/audio/audio.hpp
	 */
	class Audio {
	private:
	protected:
		/**
		 * @brief Default constructor.
		 *
		 * @note Protected to be used only by derived classes.
		 */
		Audio() = default;
	public:
		// no copy and move for Audio class
		/**
		 * @brief Copy constructor deleted.
		 */
		Audio(const Audio&) = delete;

		/**
		 * @breif Copy assignment deleted.
		 */
		Audio& operator=(const Audio&) = delete;

		/**
		 * @breif Move constructor deleted.
		 */
		Audio(Audio&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		Audio& operator=(Audio&&) = delete;

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~Audio() = default;
	};
}
