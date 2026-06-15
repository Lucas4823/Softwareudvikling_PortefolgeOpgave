cmake_minimum_required(VERSION 3.15)

project(MyGame)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(MyGame
    src/main.cpp
    src/Spil.cpp
    src/Karakter.cpp
    src/Monster.cpp
    src/Kamp.cpp
    src/Status/Status.cpp
    src/Ting/Ting.cpp
    src/Status/Poisoned.cpp
)

target_include_directories(MyGame PRIVATE include)