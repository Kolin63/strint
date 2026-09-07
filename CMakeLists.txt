cmake_minimum_required(VERSION 4.2)

project(strint)

enable_testing()
add_subdirectory(tests)

add_library(${PROJECT_NAME} src/strint.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
