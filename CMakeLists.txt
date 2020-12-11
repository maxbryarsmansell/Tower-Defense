cmake_minimum_required(VERSION 3.1.0)

project(Platformer)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(libs/glfw)
add_subdirectory(src)





