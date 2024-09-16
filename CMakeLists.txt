cmake_minimum_required(VERSION 3.10)
project(CPPCHALLENGES)                # Project name

set(CMAKE_CXX_STANDARD 17)         # Set C++ standard

# Include directories
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "lib/*.cpp")

# Add executable
add_executable(MyApp ${SOURCES})

# Optionally link any libraries
# target_link_libraries(MyApp my_library)