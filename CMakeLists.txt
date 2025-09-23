cmake_minimum_required(VERSION 3.15)
project(shoot-only)

add_executable(${PROJECT_NAME} WIN32)

find_package(SDL2)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

add_subdirectory(src)
