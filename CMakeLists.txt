cmake_minimum_required(VERSION 3.1.0)

project(Game)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(libs/glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_compile_definitions(GLFW_INCLUDE_NONE)

add_subdirectory(libs/glad)
add_subdirectory(libs/glm)
add_subdirectory(libs/entt)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")

include_directories(src/)

add_executable(Game ${SRC_FILES})

target_link_libraries(Game PRIVATE glfw glad glm EnTT)

file(GLOB_RECURSE RES_FILES "res/*.vs" "res/*.fs")
file(COPY ${RES_FILES} DESTINATION "res")



