cmake_minimum_required(VERSION 3.9)
project(particles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(SOURCE_FILES
        main.cpp headers/App.h src/App.cpp headers/Particle.h src/Particle.cpp headers/Graphics.h src/Graphics.cpp
        headers/globals.h headers/Input.h src/Input.cpp
)

include_directories(headers)

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")

    include_directories(SDL2/include/SDL2)
    link_directories(SDL2/lib)

    add_executable(particles ${SOURCE_FILES})

    target_link_libraries(particles mingw32 SDL2main SDL2)
endif()

if(UNIX AND NOT APPLE)
    include(FindPkgConfig)
    pkg_search_module(SDL2 REQUIRED sdl2)
    include_directories(${SDL2_INCLUDE_DIRS})

    add_executable(particles ${SOURCE_FILES})

    target_link_libraries(particles ${SDL2_LIBRARIES})
endif()
