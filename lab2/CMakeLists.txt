cmake_minimum_required(VERSION 3.23)

set(project "lab2")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(planet)
add_subdirectory(form)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/planets.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/form.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project} planet form)
