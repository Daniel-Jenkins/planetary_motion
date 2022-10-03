add_library(vector)

target_link_libraries(vector m)

target_sources(vector
    PRIVATE vector.c
    PUBLIC vector.h
    )

target_include_directories(vector
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}
    )
