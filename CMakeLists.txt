cmake_minimum_required(VERSION 2.8)

project(loadLib)
add_executable(${PROJECT_NAME} "main.cpp" LibLoader.cc)
target_link_libraries(${PROJECT_NAME} dl)

add_library(lib1 SHARED "lib1.cpp")
