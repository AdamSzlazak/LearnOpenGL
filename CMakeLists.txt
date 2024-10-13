cmake_minimum_required(VERSION 3.10)

project(LearnOpenGL LANGUAGES C CXX)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_STATNDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(glad STATIC source/glad.c)

add_subdirectory(lessons/HelloTriangle)

