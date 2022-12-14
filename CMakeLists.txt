cmake_minimum_required(VERSION 3.8)
project(formal_langs)

set(CMAKE_CXX_STANDARD 17)
include_directories(src)
set(SOURCES src/Helper.cpp src/Solver.cpp)
add_executable(formal_langs main.cpp ${SOURCES})
add_executable(tests tests/test.cpp ${SOURCES})
target_link_libraries(tests /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a)

