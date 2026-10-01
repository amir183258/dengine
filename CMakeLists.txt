cmake_minimum_required(VERSION 3.16)
project(DENGINE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)

enable_testing()

# gtest
find_package(GTest REQUIRED)

# SDL3
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(SDL3_mixer REQUIRED)

# engine lib
add_library(dengine STATIC
	${PROJECT_SOURCE_DIR}/src/core/math/vector_2d.cpp
	${PROJECT_SOURCE_DIR}/src/core/time/sdl_time_provider.cpp
	${PROJECT_SOURCE_DIR}/src/core/window/sdl_window.cpp
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

# for tests
add_subdirectory(tests)
