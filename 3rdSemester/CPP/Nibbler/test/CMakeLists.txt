cmake_minimum_required (VERSION 3.10)

set(SOURCE
    ../src/
)

add_compile_options(-Wall -Werror -Wextra -std=c++11)

add_executable(unittest test.cpp)