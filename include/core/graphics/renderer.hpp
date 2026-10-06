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
 * @file renderer.hpp
 *
 * @brief Defines the Renderer which renders on window.
 */

#pragma once

#include <string>

namespace dengine {
	class Window;
}

namespace dengine {

	/**
	 * @class Renderer
	 * @brief Represents renderer abstract class.
	 *
	 * This class manages drawing different objects
	 * on the windows.
	 *
	 * @headerfile core/graphics/renderer.hpp
	 */
	class Renderer {
	private:
	protected:
		/**
		 * The window of the renderer.
		 */
		Window &window_;
	public:
		/**
		 * @brief Deleted default constructor.
		 *
		 * Renderer needs Window to work, so there is no
		 * default constructor.
		 */
		Renderer() = delete;

		/**
		 * @breif Constructor using Window.
		 * 
		 * There must be a window for rendering objects.
		 *
		 * @param window The window to render.
		 */
		explicit Renderer(Window &window);

		/**
		 * @brief Clears window.
		 */
		virtual void clear() = 0;

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~Renderer() = default;
	};
}
