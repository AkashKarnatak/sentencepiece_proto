# CMakeLists.txt

cmake_minimum_required(VERSION 3.10) # Minimum CMake version required
project(sentencepiece_proto) # Project name

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

# Find the protobuf package
find_package(Protobuf REQUIRED)

# Add the path to the Protocol Buffers include directories
include_directories(${Protobuf_INCLUDE_DIRS})

# Source files
set(SOURCES
    ./src/main.cpp
    ./src/builtin_pb/sentencepiece_model.pb.cc
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against the Protocol Buffers library
target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES})
