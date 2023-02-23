add_executable(railway_tests)

file(GLOB_RECURSE RAILWAY_TESTS_INCLUDE *.hpp)
file(GLOB_RECURSE RAILWAY_TESTS_SOURCE *.cpp)

target_include_directories(railway_tests
        PUBLIC
        .
        )

target_sources(railway_tests
    PUBLIC
        ${RAILWAY_TESTS_INCLUDE}
    PRIVATE
        ${RAILWAY_TESTS_SOURCE}
    )

target_link_libraries(railway_tests
    PUBLIC
        railway
    )