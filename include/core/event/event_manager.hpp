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
 * @file event_manager.hpp
 * 
 * @brief Defines the EventManager abstract class for the dengine.
 */

#pragma once

#include <queue>

namespace dengine {
	struct Event;
}

namespace dengine {

	/**
	 * @class EventManager
	 * @brief Represents an abstract event manager.
	 *
	 * EventManager is used to manage different events such as
	 * pressing a key in the engine.
	 *
	 * @headerfile core/event_manager.hpp
	 */
	class EventManager {
	private:
	protected:
		/**
		 * @brief Default constructor.
		 *
		 * @note Protected to be used only by derived classes.
		 */
		EventManager() = default;
	public:
		// no copy and move for EventManager class.
		/**
		 * @brief Copy constructor deleted.
		 */
		EventManager(const EventManager&) = delete;

		/**
		 * @brief Copy assignment deleted.
		 */
		EventManager& operator=(const EventManager&) = delete;

		/**
		 * @brief Move constructor deleted.
		 */
		EventManager(EventManager&&) = delete;

		/**
		 * @brief Move assignment deleted.
		 */
		EventManager& operator=(EventManager&&) = delete;

		/**
		 * @brief Updates and gets the newest events.
		 *
		 * Call this at the beginning of the game loop.
		 */
		virtual void update() = 0;

		/**
		 * @brief Polls on the event queue and pull events.
		 *
		 * Call this in a loop to get all events.
		 *
		 * @param output_even The output event which should be processed.
		 *
		 * @return bool True if there is an output event, otherwise false.
		 */
		virtual bool poll(Event &output_event) = 0;

		/**
		 * @brief The abstract class virtual default destructor.
		 */
		virtual ~EventManager() = default;
	};
}
