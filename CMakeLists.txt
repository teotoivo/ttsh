cmake_minimum_required(VERSION 3.15)

project(TeoToivoShell 
    VERSION 0.1.0
    LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Compiler warnings and options
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -D_GNU_SOURCE")

# Find all source and header files recursively
file(GLOB_RECURSE SOURCE_FILES "src/*.c")
file(GLOB_RECURSE HEADER_FILES "include/*.h")

# Include directories
include_directories(include)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Generate compile_commands.json for tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create executable
add_executable(ttsh ${SOURCE_FILES} ${HEADER_FILES})

# Install target (optional)
install(TARGETS ttsh
    RUNTIME DESTINATION bin)

