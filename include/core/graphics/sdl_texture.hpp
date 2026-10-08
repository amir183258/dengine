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
 * @file sdl_texture.hpp
 * 
 * @brief Implements Texture abstract class.
 */

#pragma once

#include <string>

#include <core/graphics/texture.hpp>

namespace dengine {
	class SDLRenderer;
}
struct SDL_Texture;

namespace dengine {

	/**
	 * @class SDLTexture
	 * @brief Represents a SDL texture.
	 *
	 * This class is used as an efficient driver-specific
	 * representation of pixel data.
	 *
	 * @headerfile core/graphics/sdl_texture.hpp
	 */
	class SDLTexture : public Texture {
	private:
		/**
		 * @brief The underlying SDL texture handle.
		 */
		SDL_Texture *texture_;

		/**
		 * @brief The width of the texture.
		 *
		 * @note Width is cached because it is related to a file.
		 */
		float width_;

		/**
		 * @brief The height of the texture.
		 *
		 * @note Width is cached because it is related to a file.
		 */
		float height_;
	public:
		/**
		 * @brief Default constructor.
		 *
		 * Creates an invalid texture.
		 */
		SDLTexture();

		/**
		 * @brief Constructor uses SDLRenderer.
		 *
		 * There must be a renderer to create a texture.
		 *
		 * @param renderer The renderer to create texture.
		 */
		explicit SDLTexture(SDLRenderer &renderer, const std::string &path);

		// no copy
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLTexture(const SDLTexture&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		SDLTexture& operator=(const SDLTexture&) = delete;

		// can move
		/**
		 * @brief Move constructor.
		 *
		 * @note noexcept for using in std containers.
		 */
		SDLTexture(SDLTexture&&) noexcept;

		/**
		 * @brief Move assignment.
		 *
		 * @note noexcept for using in std containers.
		 */
		SDLTexture& operator=(SDLTexture&&) noexcept;

		/**
		 * @brief Checks if texture is valid.
		 *
		 * @return True if texture is valid, otherwise false.
		 */
		[[nodiscard]] bool is_valid() const { return texture_ != nullptr; }

		/**
		 * @brief Returns the width of the texture file.
		 *
		 * @return Width of the texture.
		 */
		[[nodiscard]] uint32_t width() const override;

		/**
		 * @brief Returns the height of the texture file.
		 *
		 * @return Height of the texture.
		 */
		[[nodiscard]] uint32_t height() const override;

		/**
		 * @brief The destructor of SDLTexture.
		 */
		~SDLTexture();
	};
}
