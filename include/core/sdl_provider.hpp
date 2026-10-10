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
 * @file sdl_provider.hpp
 * 
 * @brief Defines the SDLProvider abstract class for the dengine.
 */

#pragma once

#include <string>
#include <cstdint>
#include <memory>

#include <core/provider.hpp>

namespace dengine {
	class Init;
	class Window;
	class Renderer;
	class Texture;
	class TimeProvider;
}

namespace dengine {

	/**
	 * @class SDLProvider
	 * @brief Represents a SDL provider.
	 *
	 * This class used to create window, renderer,
	 * texture and etc using SDL3.
	 *
	 * @headerfile core/sdl_provider.hpp
	 */
	class SDLProvider : public Provider {
	private:
	public:
		/**
		 * @brief Default constructor.
		 */
		SDLProvider() = default;

		// no copy and move for SDLProvider class.
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLProvider(const SDLProvider&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		SDLProvider& operator=(const SDLProvider&) = delete;

		/**
		 * @brief Move constructor deleted.
		 */
		SDLProvider(SDLProvider&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		SDLProvider& operator=(SDLProvider&&) = delete;

		/**
		 * @brief Creates an Init.
		 *
		 * Ths Init is created using SDL3.
		 *
		 * @return A unique pointer to the Init abstract class.
		 */
		std::unique_ptr<Init> create_init() override;

		/**
		 * @brief Creates a Window.
		 *
		 * The window is created using SDL3.
		 *
		 * @param title The name of the window.
		 * @param width The width of the window.
		 * @param height The height of the window.
		 *
		 * @return A unique pointer to Window abstract class.
		 */
		std::unique_ptr<Window> create_window(const std::string &title,
				uint32_t width, uint32_t height) override;

		/**
		 * @breif Creates a Renderer.
		 *
		 * The Renderer is created using SDL3;
		 *
		 * @param window The window which renderer is based on it.
		 *
		 * @return A unique pointer to the Renderer abstract class.
		 */
		std::unique_ptr<Renderer> create_renderer(Window &window) override;

		/**
		 * @brief Creates a Texture.
		 *
		 * The Texture is created using SDL3;
		 *
		 * @param renderer The renderer for the texture.
		 * @param path The path of the texture file.
		 *
		 * @return A unique pointer to the Texture abstract class.
		 */
		std::unique_ptr<Texture> create_texture(Renderer &renderer,
				const std::string &path) override;

		/**
		 * @brief Creates a TimeProvider.
		 *
		 * The TimeProvider is created using SDL3.
		 *
		 * @return A unque pointer to the TimeProvider.
		 */
		std::unique_ptr<TimeProvider> create_time_provider() override;
		
		/**
		 * @brief The abstract class virtual default destructor.
		 */
		~SDLProvider() = default;
	};
}
