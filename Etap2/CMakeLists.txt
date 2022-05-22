cmake_minimum_required(VERSION 3.16.3)
project(Etap2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(Etap2 main.cpp Fork/Fork.cpp Fork/Fork.hpp Philosopher/Philosopher.cpp Philosopher/Philosopher.hpp)

target_link_libraries(Etap2 ncurses)
