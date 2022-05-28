cmake_minimum_required(VERSION 3.20)
project(eclair)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SFML lib/SFML)
set(PROJECT_INCLUDE_DIR include ${LIB_SFML}/include)

add_subdirectory(src)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIR})
