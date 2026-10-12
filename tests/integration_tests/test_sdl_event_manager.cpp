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
#include <memory>

#include <gtest/gtest.h>

#include <core/sdl_provider.hpp>
#include <core/window/init.hpp>
#include <core/window/window.hpp>
#include <core/graphics/renderer.hpp>
#include <core/event/event.hpp>
#include <core/event/sdl_event_manager.hpp>

class SDLEventManagerTest : public ::testing::Test {
private:
protected:
	std::unique_ptr<dengine::Init> init;
	std::unique_ptr<dengine::Window> window;
	std::unique_ptr<dengine::Renderer> renderer;
public:
	void SetUp() override {
		dengine::SDLProvider provider {};

		init = provider.create_init();

		window = provider.create_window("Test Window", 640, 480);

		renderer = provider.create_renderer(*window);
	}
};

TEST_F(SDLEventManagerTest, ExitFromWindow) {
	dengine::SDLEventManager event_manager {};

	dengine::Event event {dengine::EventType::Quit, {}};
	event_manager.add_event(event);

	dengine::Event output_event;
	EXPECT_TRUE(event_manager.poll(output_event));

	SUCCEED();
}
