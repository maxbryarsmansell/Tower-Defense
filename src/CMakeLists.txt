file(GLOB_RECURSE SRC_FILES "*.cpp")

include_directories(.)

add_executable(Platformer ${SRC_FILES})
target_link_libraries(Platformer PRIVATE glfw glad EnTT)

