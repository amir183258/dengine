#include <cstdint>
#include <gtest/gtest.h>

#include <core/time/sdl_time_provider.hpp>

TEST(SDLTimeProviderTest, NowAndSleep) {
	dengine::SDLTimeProvider t;

	uint32_t start = t.now_ms();
	t.sleep_ms(10);
	uint32_t end = t.now_ms();

	EXPECT_GE(end, start);
}
