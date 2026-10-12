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

#include <string>
#include <cstdint>
#include <memory>

#include <core/math/rectangle.hpp>
#include <core/sdl_provider.hpp>
#include <core/window/init.hpp>
#include <core/window/window.hpp>
#include <core/graphics/renderer.hpp>
#include <core/graphics/texture.hpp>
#include <core/time/time_provider.hpp>
#include <engine/fps_handler.hpp>
#include <core/event/event.hpp>
#include <core/event/event_manager.hpp>

#include <config.hpp>

using namespace dengine;

int main() {
	SDLProvider provider {};

	std::unique_ptr<Init> init = provider.create_init();
	init->initialize();

	std::unique_ptr<Window> window = provider.create_window("Test Window", 640, 800);
	std::unique_ptr<Renderer> renderer = provider.create_renderer(*window);

	// event manager
	std::unique_ptr<EventManager> event_manager = provider.create_event_manager();
	Event event {};

	// load texture
	std::unique_ptr<Texture> texture = provider.create_texture(*renderer,
			config::TEST_ASSETS_PATH + "/test_texture.png");
	
	// time management
	std::unique_ptr<TimeProvider> time_provider = provider.create_time_provider();
	FPSHandler fps_handler {*time_provider};

	// game loop
	bool running = true;
	while (running) {
		event_manager->update();
		while(event_manager->poll(event)) {
			switch (event.type) {
			case EventType::Quit:
				running = false;
				break;
			}
		}

		fps_handler.begin_frame();

		// clear
		renderer->set_draw_color(Colors::White);
		renderer->clear();

		// draw point
		renderer->set_draw_color(Colors::Blue);
		renderer->draw_point(10.0f, 10.0f);

		// draw line
		renderer->set_draw_color(Colors::Black);
		renderer->draw_line(0.0f, 0.0f, 200.0f, 200.0f);

		// draw rectangle
		renderer->set_draw_color(Colors::Red);
		renderer->draw_rect(200.0f, 200.0f, 300.0f, 100.0f);

		// draw fill rectangle
		renderer->set_draw_color(Colors::Green);
		renderer->fill_rect(250.0f, 250.0f, 100.0f, 50.0f);

		// draw texture
		renderer->draw_texture(*texture, 300.0f, 400.0f);

		renderer->present();

		fps_handler.end_frame();
	}

	return 0;
}
