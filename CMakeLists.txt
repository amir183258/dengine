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

# unit tests files
add_executable(unit_tests
	tests/unit_tests/test_rectangle.cpp
)

target_include_directories(unit_tests PRIVATE
	${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(unit_tests PRIVATE
	GTest::GTest
	GTest::Main
	pthread
)
