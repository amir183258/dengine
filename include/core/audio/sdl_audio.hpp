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
 * @file sdl_audio.hpp
 * 
 * @brief Defines the SDLAudio which implements Audio.
 */

#pragma once

#include <string>

#include <core/audio/audio.hpp>

// this is the native audio in SDL3.
namespace dengine {
	class SDLMixer;
}
struct MIX_Audio;

namespace dengine {

	/**
	 * @class SDLAudio
	 * @brief Represents a SDL audio.
	 *
	 * This class manages audio to be used in tracks
	 * for mixers. It uses native MIX_Audio in SDL3.
	 *
	 * @headerfile core/audio/sdl_audio.hpp
	 */
	class SDLAudio : public Audio {
	private:
		/**
		 * @brief The underlying SDL audio handle.
		 */
		MIX_Audio* audio_;
	public:
		/**
		 * @brief Default constructor deleted.
		 */
		SDLAudio() = delete;

		/**
		 * @brief Constructor using mixer and audio path.
		 *
		 * This constructor creates the object using the file
		 * path of an audio for a mixer.
		 *
		 * @param mixer The mixer of the audio.
		 * @param path The file path of the audio.
		 */
		SDLAudio(SDLMixer &mixer, const std::string &path);

		// no copy and move for SDLAudio class.
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLAudio(const SDLAudio&) = delete;

		/**
		 * @breif Copy assignment deleted.
		 */
		SDLAudio& operator=(const SDLAudio&) = delete;

		/**
		 * @breif Move constructor deleted.
		 */
		SDLAudio(SDLAudio&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		SDLAudio& operator=(SDLAudio&&) = delete;

		/**
		 * @brief Checks if the SDL audio is valid.
		 *
		 * @return True if valid, otherwise false.
		 */
		[[nodiscard]] bool is_valid() const { return audio_ != nullptr; }

		/**
		 * @brief Returns the native SDL audio handle.
		 *
		 * @return The current SDL audio or nullptr.
		 */
		[[nodiscard]] MIX_Audio& get_sdl_audio_handle() const;

		/**
		 * @brief The destructor of SDLAudio.
		 */
		~SDLAudio();
	};
}
