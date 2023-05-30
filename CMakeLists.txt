cmake_minimum_required(VERSION 3.24)
set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk")
project(c_plus_plus)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/wxWidgets-3.2.2.1)
add_executable(c_plus_plus kurs/Developer.cpp kurs/Staff.cpp kurs/Tester.cpp kurs/main.cpp)
target_link_libraries(c_plus_plus wx::net wx::core wx::base)

