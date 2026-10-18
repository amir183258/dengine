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
 * @file sdl_mixer.hpp
 * 
 * @brief Defines the SDLMixer which implements Mixer.
 */

#pragma once

#include <core/audio/mixer.hpp>

// this is the native mixer in SDL3.
struct MIX_Mixer;

namespace dengine {

	/**
	 * @class SDLMixer
	 * @brief Represents a SDL mixer.
	 *
	 * This class manages the audio mixer for engine using
	 * MIX_Mixer struct in SDL3.
	 *
	 * @headerfile core/audio/sdl_mixer.hpp
	 */
	class SDLMixer : public Mixer {
	private:
		/**
		 * @brief The underlying SDL mixer handle.
		 */
		MIX_Mixer* mixer_;
	public:
		/**
		 * @brief Defualt constructor.
		 *
		 * Creates a mixer using default audio device.
		 */
		SDLMixer();

		// no copy and move for SDLMixer class.
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLMixer(const SDLMixer&) = delete;

		/**
		 * @breif Copy assignment deleted.
		 */
		SDLMixer& operator=(const SDLMixer&) = delete;

		/**
		 * @breif Move constructor deleted.
		 */
		SDLMixer(SDLMixer&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		SDLMixer& operator=(SDLMixer&&) = delete;

		/**
		 * @brief Checks if the sdl mixer is valid.
		 *
		 * @return True if valid and false if not valid.
		 */
		[[nodiscard]] bool is_valid() const { return mixer_ != nullptr; }

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~SDLMixer() = default;
	};
}
