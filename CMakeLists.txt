# CMakeLists.txt

cmake_minimum_required(VERSION 3.10) # Minimum CMake version required
project(sentencepiece_proto) # Project name

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(sentencepiece_proto src/main.cpp)
