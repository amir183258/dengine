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

#include <queue>

#include <SDL3/SDL.h>

#include <core/event/sdl_event_manager.hpp>
#include <core/event/event.hpp>

namespace dengine {
	void SDLEventManager::update() {
		SDL_Event sdl_event;
		while (SDL_PollEvent(&sdl_event)) {
			switch (sdl_event.type) {
			case SDL_EVENT_QUIT:
				events_.push({EventType::Quit, {}});
				break;
			}
		}
	}

	bool SDLEventManager::poll(Event &output_event) {
		if (events_.empty())
			return false;
		output_event = events_.front();
		events_.pop();
		return true;
	}

	void SDLEventManager::add_event(const Event &event) {
		events_.push(event);
	}
}
