file(GLOB HelloWindow_Sources source/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(HelloWindow ${HelloWindow_Sources})

target_link_libraries(HelloWindow glfw glad)
