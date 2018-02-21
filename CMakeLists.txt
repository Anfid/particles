cmake_minimum_required(VERSION 3.9)
project(particles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -mwindows")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(headers SDL2/include/SDL2)
link_directories(SDL2/lib)

add_executable(particles main.cpp headers/App.h src/App.cpp headers/Particle.h src/Particle.cpp headers/Graphics.h src/Graphics.cpp headers/globals.h headers/Input.h src/Input.cpp)

target_link_libraries(particles mingw32 SDL2main SDL2)

