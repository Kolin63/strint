cmake_minimum_required(VERSION 4.2)

add_executable(test1 test1.c)
target_link_libraries(test1 PRIVATE strint)
add_test(NAME test1 COMMAND test1)
set_target_properties(test1 PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)

add_executable(test2 test2.c)
target_link_libraries(test2 PRIVATE strint)
add_test(NAME test2 COMMAND test2)
set_target_properties(test2 PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON)
