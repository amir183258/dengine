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
 * @file sdl_text_maker.hpp
 * 
 * @brief Implements TextMaker abstract class.
 */

#pragma once

#include <string>
#include <memory>
#include <cstdint>

#include <core/graphics/color.hpp>
#include <core/graphics/text_maker.hpp>

namespace dengine {
	class SDLRenderer;
}
struct TTF_Font;
struct SDL_Renderer;

namespace dengine {

	/**
	 * @class SDLTextMaker
	 * @brief Represents a SDL text maker.
	 *
	 * This class is used to make text textures to be used on
	 * the screen.
	 *
	 * @headerfile core/graphics/sdl_text_maker.hpp
	 */
	class SDLTextMaker : public TextMaker {
	private:
		/**
		 * @brief The text color;
		 */
		Color text_color_;

		/**
		 * @brief The underlying SDL font handle.
		 */
		TTF_Font *font_;

		/**
		 * @brief The renderer used to make text textures.
		 */
		const SDLRenderer* const renderer_;
	public:
		/**
		 * @brief Deleted default constructor.
		 *
		 * SDLTextMaker needs font path and size to be created.
		 */
		SDLTextMaker() = delete;

		/**
		 * @brief Constructor using a font file path.
		 *
		 * There must be a font to create a SDLTextMaker.
		 */
		explicit SDLTextMaker(SDLRenderer* renderer,
				const std::string &font_path, int size);

		// no copy and move for SDLTextMaker class.
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLTextMaker(const SDLTextMaker&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		SDLTextMaker& operator=(const SDLTextMaker&) = delete;

		/**
		 * @brief Move Constructor deleted.
		 */
		SDLTextMaker(SDLTextMaker&&) = delete; 

		/**
		 * @brief Move assignment deleted.
		 */
		SDLTextMaker& operator=(SDLTextMaker&&) = delete;

		/**
		 * @brief Checks if font is valid.
		 *
		 * @return True if font is valid, otherwise false.
		 */
		bool is_valid() const { return font_ != nullptr; }

		/**
		 * @brief Sets the color of the output texture.
		 *
		 * @param font_color The input text color.
		 */
		void set_color(const Color &font_color) override;

		/**
		 * @brief Create a text texture and returns a pointer to it.
		 *
		 * @param text The input text.
		 *
		 * @return The pointer to the output text texture.
		 */
		std::unique_ptr<Texture> make_text(const std::string &text) override;

		/**
		 * @brief The destructor of SDLTextMaker.
		 */
		~SDLTextMaker();
	};
}
