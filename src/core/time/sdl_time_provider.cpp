#include <cstdint>

#include <SDL3/SDL.h>

#include <core/time/sdl_time_provider.hpp>

namespace dengine {

	uint32_t SDLTimeProvider::now_ms() {
		return SDL_GetTicks();
	}

	void SDLTimeProvider::sleep_ms(uint32_t ms) {
		SDL_Delay(ms);
	}
}
