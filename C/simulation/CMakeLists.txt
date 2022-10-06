add_executable(simulation simulation.c)

target_link_libraries(simulation
    PRIVATE vector
    PRIVATE celestial_system
    )

target_sources(simulation
    PRIVATE simulation.c
    PRIVATE simulation.h
    )
