#include <cstdint>
#include <gtest/gtest.h>

#include <core/time/time_provider.hpp>
#include <engine/fps_handler.hpp>
#include <mock_time_provider.hpp>

TEST(FPSHandlerTest, DefaultFPS) {
	dengine::tests::MockTimeProvider fake_time;
	dengine::FPSHandler fps_handler {fake_time};

	SUCCEED();
}

TEST(FPSHandlerTest, ConstructorWithFPSValue) {
	dengine::tests::MockTimeProvider fake_time;
	dengine::FPSHandler fps_handler {fake_time, 30};

	SUCCEED();
}

TEST(FPSHandlerTest, FPSDrop) {
	dengine::tests::MockTimeProvider fake_time;

	dengine::FPSHandler fps_handler {fake_time};

	// frame_start is 0
	fps_handler.begin_frame();

	// wait 70 ms
	fake_time.sleep_ms(70);

	// now current_fps should be less than 60
	fps_handler.end_frame();

	SUCCEED();
}

TEST(FPSHandlerTest, Stable60FPS) {
	dengine::tests::MockTimeProvider fake_time;
	dengine::FPSHandler fps_handler {fake_time};

	fps_handler.begin_frame();
	fake_time.sleep_ms(16);
	fps_handler.end_frame();

	SUCCEED();
}

TEST(FPSHandlerTest, ZeroDeltaTime) {
	dengine::tests::MockTimeProvider fake_time;
	dengine::FPSHandler fps_handler {fake_time};

	fps_handler.begin_frame();
	fps_handler.end_frame();
	
	SUCCEED();
}

TEST(FPSHandlerTest, SetAndGetTargetFPS) {
	dengine::tests::MockTimeProvider fake_time;
	dengine::FPSHandler fps_handler {fake_time};

	uint32_t target = 11;
	fps_handler.set_target_fps(target);

	EXPECT_EQ(fps_handler.get_target_fps(), target);
}
