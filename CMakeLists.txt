cmake_minimum_required(VERSION 3.25)
project(8085_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(8085_cpp
        src/Arithmetic.cpp
        src/Branching.cpp
        src/Load_and_Store.cpp
        src/Logical.cpp
        src/main.cpp
        src/Set.cpp src/Utils/Utils.cpp src/Utils/Utils.h src/Arithmetic.h src/Essentials.h src/Logical.h)
