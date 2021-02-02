cmake_minimum_required(VERSION 3.18.4)
project(kata CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)