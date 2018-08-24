cmake_minimum_required (VERSION 3.11 FATAL_ERROR)

project(sfml)

include(FetchContent)

FetchContent_Declare(
    sfml_download
    URL https://www.sfml-dev.org/files/SFML-2.4.2-sources.zip
)

FetchContent_GetProperties(sfml_download)

if(NOT sfml_download_POPULATED)
    FetchContent_Populate(sfml_download)
    set(BUILD_SHARED_LIBS TRUE)
    add_subdirectory(${sfml_download_SOURCE_DIR} ${sfml_download_BINARY_DIR})
endif()

include_directories(${sfml_download_SOURCE_DIR}/include)

add_library(sfml SHARED
        src/Functions.cpp
		../src/ErrorRefactor.cpp)

target_link_libraries(sfml sfml-graphics sfml-system sfml-window)
