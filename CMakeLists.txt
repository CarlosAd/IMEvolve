cmake_minimum_required(VERSION 2.8)

project (IMEvolve)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_definitions("-std=c++11")

include_directories("${PROJECT_SOURCE_DIR}/include")
add_subdirectory(include)

include_directories("${PROJECT_SOURCE_DIR}/src")
add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main bibliotecas)
