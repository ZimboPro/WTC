cmake_minimum_required (VERSION 3.11 FATAL_ERROR)

project(nibbler)

set(CMAKE_CXX_STANDARD 17)
if(APPLE)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -stdlib=libc++")
elseif(UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")
endif(APPLE)



include_directories(include)

add_executable (nibbler
    src/main.cpp
    src/Loop.cpp
    src/Factory.cpp
    src/Snake.cpp
    src/GameElement.cpp
    src/ErrorRefactor.cpp
)

if(UNIX AND NOT APPLE)
    target_link_libraries(nibbler dl)
endif()

include(ExternalProject)

add_subdirectory(sdl)

add_subdirectory(opengl)
    
add_subdirectory(sfml)
