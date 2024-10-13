file(GLOB HelloTriangle_Sources source/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/lessons/HelloTriangle/incl)

add_executable(HelloTriangle ${HelloTriangle_Sources})

target_link_libraries(HelloTriangle glfw glad)