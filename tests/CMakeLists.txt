# unit tests files
add_executable(unit_tests
	${PROJECT_SOURCE_DIR}/tests/unit_tests/test_rectangle.cpp
	${PROJECT_SOURCE_DIR}/tests/unit_tests/test_vector_2d.cpp
	${PROJECT_SOURCE_DIR}/tests/unit_tests/test_color.cpp
	${PROJECT_SOURCE_DIR}/tests/unit_tests/test_fps_handler.cpp
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

add_test(NAME UnitTests COMMAND unit_tests)

# integration tests files
add_executable(integration_tests
	${PROJECT_SOURCE_DIR}/tests/integration_tests/test_sdl_time_provider.cpp
	${PROJECT_SOURCE_DIR}/tests/integration_tests/test_sdl_init.cpp
	${PROJECT_SOURCE_DIR}/tests/integration_tests/test_sdl_window.cpp
	${PROJECT_SOURCE_DIR}/tests/integration_tests/test_sdl_renderer.cpp
)

target_include_directories(integration_tests PRIVATE
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_BINARY_DIR}/generated
)

target_link_libraries(integration_tests PRIVATE
	GTest::GTest
	GTest::Main
	pthread

	dengine
)

add_test(NAME IntegrationTests COMMAND integration_tests)
