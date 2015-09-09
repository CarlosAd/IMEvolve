project (IMEvolve)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_definitions("-std=c++11")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})
