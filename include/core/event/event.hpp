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
 * @file event.hpp
 * 
 * @brief Defines the Event struct for the dengine.
 */

#pragma once

#include <variant>

namespace dengine {

	/**
	 * @enum EventType
	 * @brief Defines the types of events supported by the engine.
	 *
	 * @headerfile core/event/event.hpp
	 */
	enum class EventType {
		Quit
	};

	/**
	 * @struct Event
	 * @brief Represents a generic wrapper used for communication withing the engine.
	 *
	 * This structure bundles the event type with its associated data payload
	 * using a variant to store different event-specific information.
	 *
	 * @headerfile core/event/event.hpp
	 */
	struct Event {
		EventType type;
		std::variant<std::monostate, int, float> data;
	};
}
