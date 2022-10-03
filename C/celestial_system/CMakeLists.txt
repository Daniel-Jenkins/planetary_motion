add_library(celestial_system)

target_link_libraries(celestial_system PRIVATE vector m)
target_compile_options(celestial_system PRIVATE -Wall -Wextra -Wpedantic -Werror)

target_sources(celestial_system
    PRIVATE celestial_system.c
    PUBLIC celestial_system.h
    )

target_include_directories(vector
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
    )

