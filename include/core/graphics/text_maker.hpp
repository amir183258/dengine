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
 * @file text_maker.hpp
 *
 * @brief Defines the TextMaker class used to create text textures.
 */

#pragma once

#include <string>
#include <memory>
#include <cstdint>

#include <core/graphics/color.hpp>

namespace dengine {
	class Texture;
}

namespace dengine {

	/**
	 * @class TextMaker 
	 * @brief Represents an abstract text maker.
	 *
	 * This class is used to create text textures.
	 *
	 * @headerfile core/graphics/text_maker.hpp
	 */
	class TextMaker {
	private:
	protected:
		/**
		 * @brief Default constructor.
		 *
		 * @note Protected to be used only by derived classes.
		 */
		TextMaker() = default;
	public:
		// no copy and move for TextMaker class.
		/**
		 * @brief Copy constructor deleted.
		 */
		TextMaker(const TextMaker&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		TextMaker& operator=(const TextMaker&) = delete;

		/**
		 * @brief Move Constructor deleted.
		 */
		TextMaker(TextMaker&&) = delete; 

		/**
		 * @brief Move assignment deleted.
		 */
		TextMaker& operator=(TextMaker&&) = delete;

		/**
		 * @brief Sets the color of the text.
		 *
		 * @param font_color The text color.
		 */
		virtual void set_color(const Color &font_color) = 0;

		/**
		 * @brief Draws text on the screen.
		 *
		 * @param text The input text.
		 */
		virtual std::unique_ptr<Texture> make_text(const std::string &text) = 0;

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~TextMaker() = default;
	};
}
