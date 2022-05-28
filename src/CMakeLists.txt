set(TARGET eclair)

file(GLOB PROJECT_SOURCES
    *.cpp
    cursor/*.cpp
    document/*.cpp
    editor/*.cpp
    input/*.cpp
    selection/*.cpp
    special/*.cpp
    utility/*.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
