cmake_minimum_required(VERSION 3.20)
project(dengine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type" FORCE)
endif()

# for installing
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# config macros
set(TEST_ASSETS_PATH ${CMAKE_SOURCE_DIR}/tests/test_assets)

configure_file(
	${PROJECT_SOURCE_DIR}/config/version.hpp.in
	${PROJECT_BINARY_DIR}/generated/version.hpp
	@ONLY
)

configure_file(
	${PROJECT_SOURCE_DIR}/config/config.hpp.in
	${PROJECT_BINARY_DIR}/generated/config.hpp
	@ONLY
)

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
	${PROJECT_SOURCE_DIR}/src/core/graphics/sdl_renderer.cpp
	${PROJECT_SOURCE_DIR}/src/core/graphics/sdl_texture.cpp
	${PROJECT_SOURCE_DIR}/src/core/sdl_provider.cpp
	${PROJECT_SOURCE_DIR}/src/core/event/sdl_event_manager.cpp
	${PROJECT_SOURCE_DIR}/src/core/graphics/sdl_text_maker.cpp
	${PROJECT_SOURCE_DIR}/src/core/audio/sdl_mixer.cpp
	${PROJECT_SOURCE_DIR}/src/core/audio/sdl_audio.cpp
	${PROJECT_SOURCE_DIR}/src/engine/fps_handler.cpp
	${PROJECT_SOURCE_DIR}/src/engine/animation.cpp
	${PROJECT_SOURCE_DIR}/src/engine/frame_clock.cpp
)
add_library(dengine::dengine ALIAS dengine)

target_include_directories(dengine PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/generated>
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/dengine>
)

target_link_libraries(dengine PUBLIC
	SDL3::SDL3
	SDL3_image::SDL3_image
	SDL3_ttf::SDL3_ttf
	SDL3_mixer::SDL3_mixer
)

# install
install(TARGETS dengine
	EXPORT dengine-targets
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dengine)
install(DIRECTORY ${PROJECT_BINARY_DIR}/generated/  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dengine)

install(EXPORT dengine-targets
	FILE dengine-targets.cmake
	NAMESPACE dengine::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dengine
)

write_basic_package_version_file(
	    "${CMAKE_CURRENT_BINARY_DIR}/dengine-config-version.cmake"
	    VERSION ${PROJECT_VERSION}
	    COMPATIBILITY ExactVersion
)

configure_package_config_file(
	"cmake/dengine-config.in.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/dengine-config.cmake"
	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dengine
)

install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/dengine-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/dengine-config-version.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/dengine
)

# for tests
add_subdirectory(tests)

# install and uninstall
include(CPack)
