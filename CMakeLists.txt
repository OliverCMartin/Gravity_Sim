cmake_minimum_required(VERSION 4.1)
project(Gravity_Sim)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

add_executable(Gravity_Sim
        src/main.cpp
        src/rendering/Renderer.cpp
        src/rendering/Renderer.h)

target_link_libraries(Gravity_Sim PRIVATE SDL2::SDL2)