add_executable(population_test population_test.c)
target_link_libraries(population_test 
    PRIVATE vector
    PRIVATE celestial_system
    )
add_test(
    NAME population_test
    COMMAND $<TARGET_FILE:population_test>
    )

add_executable(kinematic_test kinematics_test.c)
target_link_libraries(kinematic_test 
    PRIVATE vector
    PRIVATE celestial_system
    )
add_test(
    NAME kinematic_test
    COMMAND $<TARGET_FILE:kinematic_test>
    )
