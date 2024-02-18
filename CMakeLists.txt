cmake_minimum_required(VERSION 3.5)

project("8085 Simulator")

add_executable(8085_cpp src/main.cpp src/Arithmetic.cpp src/Branching.cpp src/Debugger.cpp src/Load_and_Store.cpp src/Logical.cpp src/Utils/Utils.cpp)
target_include_directories(8085_cpp PUBLIC src/Headers src/Utils)

enable_testing()
add_subdirectory(external/googletest)
include_directories(external/googletest/include)
add_executable(tests src/tests/arithmetic_test.cpp src/Arithmetic.cpp src/Branching.cpp src/Debugger.cpp src/Load_and_Store.cpp src/Logical.cpp src/Utils/Utils.cpp) 

target_link_libraries(tests PRIVATE gtest) 

include(GoogleTest)
gtest_discover_tests(tests)
