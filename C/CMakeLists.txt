cmake_minimum_required(VERSION 3.16)

project(planets LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(vector)
add_subdirectory(celestial_system)
# add_subdirectory(simulation)

include(CTest)
enable_testing()

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
