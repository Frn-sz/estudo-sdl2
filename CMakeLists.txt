cmake_minimum_required(VERSION 3.10)

project(estudo-sdl)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL3 REQUIRED sdl3)

add_executable(prog src/opengl/main.cpp libs/glad/src/glad.c)

target_include_directories(prog PRIVATE ${SDL3_INCLUDE_DIRS} libs/glad/include)

target_link_libraries(prog ${SDL3_LIBRARIES} dl)
