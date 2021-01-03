file(GLOB_RECURSE SRC_FILES "*.cpp")

include_directories(.)

source_group("src" FILES ${SRC_FILES})

add_executable(Platformer ${SRC_FILES})

target_link_libraries(Platformer PRIVATE glfw)

message(STATUS "${GLEW_DIR}/include")
