cmake_minimum_required(VERSION 3.23)

set(project "Polinom")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_HEADERS
        Polinomial.h Vector.h Term.h)

set(${project}_SOURCES
        Polinomial.cpp Vector.cpp Term.cpp)


set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})