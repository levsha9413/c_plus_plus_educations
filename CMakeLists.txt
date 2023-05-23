cmake_minimum_required(VERSION 3.24)
set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk")
project(c_plus_plus)

set(CMAKE_CXX_STANDARD 17)


add_executable(c_plus_plus lr9/main.cpp lr9/Money.cpp)
