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
 * @file sdl_event_manager.hpp
 * 
 * @brief Implements EventManager class.
 */

#pragma once

#include <queue>

#include <core/event/event_manager.hpp>
#include <core/event/event.hpp>

namespace dengine {
	/**
	 * @class SDLEventManager
	 * @brief Represents a SDL event manager.
	 *
	 * SDLEventManger handles events using SDL3 library functions.
	 *
	 * @headerfile core/event_manager/sdl_event_manager.hpp
	 */
	class SDLEventManager : public EventManager {
	private:
		/**
		 * @brief The queue which events are polled from it.
		 */
		std::queue<Event> events_;
	public:
		/**
		 * @brief Default contructor.
		 */
		SDLEventManager() = default;

		// no copy and move for SDLEventManager class.
		/**
		 * @brief Copy constructor deleted.
		 */
		SDLEventManager(const SDLEventManager&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		SDLEventManager& operator=(const SDLEventManager&) = delete;

		/**
		 * @brief Move constructor deleted.
		 */
		SDLEventManager(SDLEventManager&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		SDLEventManager& operator=(SDLEventManager&&) = delete;

		/**
		 * @brief Updates and gets the newest events.
		 *
		 * Call this at the beginning of the game loop.
		 */
		void update() override;

		/**
		 * @brief Polls on the event queue and pull events.
		 *
		 * Call this in a loop to get all events.
		 *
		 * @param output_even The output event which should be processed.
		 *
		 * @return bool True if there is an output event, otherwise false.
		 */
		bool poll(Event &output_event) override;

		/**
		 * @brief Adds an event to the event queue.
		 *
		 * @param event The input event for the queue.
		 */
		void add_event(const Event &output_event);

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		~SDLEventManager() = default;
	};
}
