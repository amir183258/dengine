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
 * @file provider.hpp
 * 
 * @brief Defines the Provider abstract class for the dengine.
 */

#pragma once

#include <string>
#include <cstdint>
#include <memory>

namespace dengine {
	class Init;
	class Window;
	class Renderer;
	class Texture;
	class TimeProvider;
}

namespace dengine {

	/**
	 * @class Provider
	 * @brief Represents an abstract provider.
	 *
	 * Provider is an abstract layer to create window,
	 * renderer, texture and etc.
	 *
	 * @headerfile core/provider.hpp
	 */
	class Provider {
	private:
	protected:
		/**
		 * @brief Default constructor.
		 *
		 * @note Protected to be used only by derived classes.
		 */
		Provider() = default;
	public:
		// no copy and move for Provider class.
		/**
		 * @brief Copy constructor deleted.
		 */
		Provider(const Provider&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		Provider& operator=(const Provider&) = delete;

		/**
		 * @brief Move constructor deleted.
		 */
		Provider(Provider&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		Provider& operator=(Provider&&) = delete;

		/**
		 * @brief Creates an Init.
		 *
		 * The Init is determined in derived class.
		 *
		 * @return A unique pointer to the Init abstract class.
		 */
		virtual std::unique_ptr<Init> create_init() = 0;

		/**
		 * @brief Creates a Window.
		 *
		 * The window is determined in derived class.
		 *
		 * @param title The name of the window.
		 * @param width The width of the window.
		 * @param height The height of the window.
		 *
		 * @return A unique pointer to Window abstract class.
		 */
		virtual std::unique_ptr<Window> create_window(const std::string &title,
				uint32_t width, uint32_t height) = 0;

		/**
		 * @breif Creates a Renderer.
		 *
		 * The Renderer is determined in derived class.
		 *
		 * @param window The window which renderer is based on it.
		 *
		 * @return A unique pointer to the Renderer abstract class.
		 */
		virtual std::unique_ptr<Renderer> create_renderer(Window &window) = 0;

		/**
		 * @brief Creates a Texture.
		 *
		 * The Texture is determined in derived class.
		 *
		 * @param renderer The renderer for the texture.
		 * @param path The path of the texture file.
		 *
		 * @return A unique pointer to the Texture abstract class.
		 */
		virtual std::unique_ptr<Texture> create_texture(Renderer &renderer,
				const std::string &path) = 0;

		/**
		 * @brief Creates a TimeProvider.
		 *
		 * The TimeProvider is determined in derived class.
		 *
		 * @return A unque pointer to the TimeProvider.
		 */
		virtual std::unique_ptr<TimeProvider> create_time_provider() = 0;
		
		/**
		 * @brief The abstract class virtual default destructor.
		 */
		~Provider() = default;
	};
}
