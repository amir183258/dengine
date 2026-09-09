cmake_minimum_required(VERSION 3.16)
project(DENGINE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)

# gtest
find_package(GTest REQUIRED)

# SDL3
set(ENV{PKG_CONFIG_PATH} "/usr/local/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED sdl3) 
pkg_check_modules(SDL3_IMAGE REQUIRED sdl3-image)
pkg_check_modules(SDL3_TTF REQUIRED sdl3-ttf)
pkg_check_modules(SDL3_MIXER REQUIRED sdl3-mixer)

# engine lib
add_library(dengine STATIC
	${PROJECT_SOURCE_DIR}/src/core/math/vector_2d.cpp
	${PROJECT_SOURCE_DIR}/src/core/time/sdl_time_provider.cpp
	${PROJECT_SOURCE_DIR}/src/core/window/sdl_init.cpp
	${PROJECT_SOURCE_DIR}/src/engine/fps_handler.cpp
)

target_include_directories(dengine PRIVATE
	${PROJECT_SOURCE_DIR}/include

	# SDL3
	${SDL3_INCLUDE_DIRS}
	${SDL3_IMAGE_INCLUDE_DIRS}
	${SDL3_TIF_INCLUDE_DIRS}
	${SDL3_MIXER_INCLUDE_DIRS}
)

target_link_libraries(dengine PRIVATE
	# SDL3
	${SDL3_LIBRARIES}
	${SDL3_IMAGE_LIBRARIES}
	${SDL3_TIF_LIBRARIES}
	${SDL3_MIXER_LIBRARIES}
)

# unit tests files
add_executable(unit_tests
	${PROJECT_SOURCE_DIR}/tests/unit_tests/test_rectangle.cpp
	${PROJECT_SOURCE_DIR}/tests/unit_tests/test_vector_2d.cpp
	${PROJECT_SOURCE_DIR}/tests/unit_tests/test_color.cpp
)

target_include_directories(unit_tests PRIVATE
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/tests/mocks
)

target_link_libraries(unit_tests PRIVATE
	GTest::GTest
	GTest::Main
	pthread

	dengine
)

# integration tests files
add_executable(integration_tests
	${PROJECT_SOURCE_DIR}/tests/integration_tests/test_sdl_time_provider.cpp
)

target_include_directories(integration_tests PRIVATE
	${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(integration_tests PRIVATE
	GTest::GTest
	GTest::Main
	pthread

	dengine
)
