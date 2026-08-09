cmake_minimum_required(VERSION 4.1)
project(Gravity_Sim)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(Gravity_Sim
        src/main.cpp
        src/rendering/Renderer.cpp
        src/rendering/Renderer.h
        src/physics/Body.cpp
        src/physics/Body.h
        src/rendering/Camera.cpp
        src/rendering/Camera.h
)

target_link_libraries(Gravity_Sim
        PRIVATE
        SDL2::SDL2
        SDL2_ttf::SDL2_ttf
)