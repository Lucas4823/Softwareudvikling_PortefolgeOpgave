cmake_minimum_required(VERSION 3.15)

project(main)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(main
    src/main.cpp
    src/Spil.cpp
    src/Karakter.cpp
    src/Monster.cpp
    src/Kamp.cpp
)