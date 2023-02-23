add_library(railway)

file(GLOB_RECURSE RAILWAY_INCLUDE *.hpp)
file(GLOB_RECURSE RAILWAY_SOURCE *.cpp)

target_include_directories(railway
    PUBLIC
        .
    )

target_sources(railway
    PUBLIC
        ${RAILWAY_INCLUDE}
    PRIVATE
        ${RAILWAY_SOURCE}
    )