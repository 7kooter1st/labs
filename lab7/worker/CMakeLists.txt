cmake_minimum_required(VERSION 3.23)

set(project "worker")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_HEADERS
        Vector.h abstract_class.h administration.h enginer.h hr.h)

set(${project}_SOURCES
        functions.cpp)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})