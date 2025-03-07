 cmake_minimum_required(VERSION 3.15)
 

 project(TeoToivoShell C)
 

 set(CMAKE_STANDARD 23)
 set(CMAKE_C_STANDARD 23)
 set(CMAKE_C_STANDARD_REQUIRED ON)
 

 set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
 

 file(GLOB_RECURSE SOURCE_FILES "src/*.c")
 

 include_directories(include)
 

 set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
 

 set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
 

 add_executable(ttsh ${SOURCE_FILES})

