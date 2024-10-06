cmake_minimum_required(VERSION 3.10)

project(estudo-sdl)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED sdl3)

add_executable(prog src/main.cpp)

target_include_directories(prog PRIVATE ${SDL3_INCLUDE_DIRS})
target_link_libraries(prog ${SDL3_LIBRARIES} dl)
