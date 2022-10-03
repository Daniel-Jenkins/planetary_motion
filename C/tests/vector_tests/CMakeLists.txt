add_executable(vector_add_test vector_add_test.c)
target_link_libraries(vector_add_test PRIVATE vector)
add_test(
    NAME vec_add_test
    COMMAND $<TARGET_FILE:vector_add_test>
    )

add_executable(vector_sub_test vector_sub_test.c)
target_link_libraries(vector_sub_test PRIVATE vector)
add_test(
    NAME vec_sub_test
    COMMAND $<TARGET_FILE:vector_sub_test>
    )

add_executable(vector_mag_test vector_mag_test.c)
target_link_libraries(vector_mag_test PRIVATE vector)
add_test(
    NAME vec_mag_test
    COMMAND $<TARGET_FILE:vector_mag_test>
    )
