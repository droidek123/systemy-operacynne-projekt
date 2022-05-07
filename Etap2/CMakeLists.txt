cmake_minimum_required(VERSION 3.16.3)
project(Etap2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Etap2 main.cpp Fork/Fork.cpp Fork/Fork.hpp Philosopher/Philosopher.cpp Philosopher/Philosopher.hpp Table/Table.cpp Table/Table.hpp GUI/Gui.cpp GUI/Gui.hpp)
