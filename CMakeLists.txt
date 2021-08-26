cmake_minimum_required(VERSION 3.10)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(lv_binding_cpp VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lvgl)
add_subdirectory(lv_drivers)

file(GLOB_RECURSE SOURCES ./lv_cpp/*.cpp)
add_library(lv_binding_cpp STATIC ${SOURCES})

target_include_directories (lvgl PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories (lv_drivers PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories (lv_binding_cpp PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(lv_binding_cpp lv_drivers)
target_link_libraries(lv_binding_cpp lvgl)


