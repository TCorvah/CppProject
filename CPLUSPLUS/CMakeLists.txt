cmake_minimum_required(VERSION 3.16)
project(calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

add_compile_options(-Wall -Wextra -Wpedantic -O2)

add_executable(calculator
    src/main.cpp
    src/driver.cpp
    src/lexer.cpp
    src/parser.cpp
    src/error.cpp
)

target_include_directories(calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#add_compile_options(-fsanitize=address -fsanitize=undefined)

