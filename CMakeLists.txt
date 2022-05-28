cmake_minimum_required(VERSION 3.20)
project(eclair)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SFML lib/SFML)

file(GLOB PROJECT_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include ${LIB_SFML}/include)
