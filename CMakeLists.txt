cmake_minimum_required(VERSION 4.2)

project(strint)

option(ENABLE_PRINT "Enable printing" ON)

if(ENABLE_PRINT)
  add_definitions(-DENABLE_PRINT)
endif(ENABLE_PRINT)

enable_testing()
add_subdirectory(tests)

add_library(${PROJECT_NAME} src/strint.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
