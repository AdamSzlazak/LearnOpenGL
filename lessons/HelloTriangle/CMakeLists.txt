file (GLOB HelloTriangle_Source source/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(HelloTriangle ${HelloTriangle_Source})

target_link_libraries(HelloTriangle glad glfw)
