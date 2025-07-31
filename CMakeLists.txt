cmake_minimum_required(VERSION 3.10)
project(MostlyForces LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Collect sources
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
    src/*.c
)

# Build as a static library
add_library(MostlyForces STATIC ${SOURCES})

# Build as an Executable
add_executable(MostlyForcesApp ${SOURCES})

# Include headers for anyone linking MostlyForces
target_include_directories(MostlyForces PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
