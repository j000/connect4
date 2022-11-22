cmake_minimum_required(VERSION 3.22)

project(connect4 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(connect4
    src/main.cxx
)
