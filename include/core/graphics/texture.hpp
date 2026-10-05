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
 * @file texture.hpp
 * 
 * @brief Defines the Texture abstract class for the dengine.
 */

#pragma once

#include <cstdint>

namespace dengine {

	/**
	 * @class Texture
	 * @brief Represents an abstract texture.
	 *
	 * Textures are used to define different game objects. They
	 * are needed to create animations.
	 *
	 * @headerfile core/graphics/texture.hpp
	 */
	class Texture {
	private:
	public:
		/**
		 * @brief Returns the width of the texture.
		 *
		 * @return The width of this texture.
		 */
		virtual uint32_t width() const = 0;

		/**
		 * @brief Returns the height of the texture.
		 *
		 * @return The height of this texture.
		 */
		virtual uint32_t height() const = 0;

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~Texture() = default;
	}
}
