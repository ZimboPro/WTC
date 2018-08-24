cmake_minimum_required (VERSION 3.11 FATAL_ERROR)

project(og)

include(FetchContent)

FetchContent_Declare(
    opengl_download
    URL https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip
)

FetchContent_GetProperties(sfml_download)

if(NOT opengl_download_POPULATED)
    FetchContent_Populate(opengl_download)
    add_subdirectory(${opengl_download_SOURCE_DIR} ${opengl_download_BINARY_DIR})
endif()

include_directories(${opengl_download_SOURCE_DIR}/include)

add_library(og SHARED
        src/Functions.cpp
		../src/ErrorRefactor.cpp)

	#find_package (PkgConfig REQUIRED)
find_package (OpenGL REQUIRED)

target_link_libraries (og ${OPENGL_LIBRARIES})
target_link_libraries(og glfw)
