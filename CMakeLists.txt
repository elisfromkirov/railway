cmake_minimum_required(VERSION 3.21)
project(railway)

include(cmake/build_options.cmake)
include(cmake/compile_options.cmake)

if(BUILD_WITH_EXAMPLE)
    add_subdirectory(test)
endif()

add_subdirectory(source)

if(BUILD_WITH_TEST)
    add_subdirectory(test)
endif()

add_subdirectory(third_party)

if(BUILD_WITH_WORKLOAD)
    add_subdirectory(workload)
endif()