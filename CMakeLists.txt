cmake_minimum_required(VERSION 3.24)
project(c_plus_plus)

set(CMAKE_CXX_STANDARD 14)

include_directories(semestr4/lab1)

add_executable(c_plus_plus
        semestr4/lab1/Task1/Task1.cpp
        semestr4/lab1/Task1/Task1.h semestr4/lab1/Task2and3.cpp)
