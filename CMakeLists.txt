cmake_minimum_required(VERSION 3.10)
project(Matrices)

# program
add_executable(program sources/main.cpp)

# tests
set(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/googletest)
set(TEST_SOURCES tests/main.cpp)

add_executable(test_program ${TEST_SOURCES})
target_link_libraries(test_program ${GTEST_DIR}/build/lib/libgtest.dll.a)

set(GTEST_INCLUDE_DIR PUBLIC ${GTEST_DIR}/googletest/include)
target_include_directories(test_program ${GTEST_INCLUDE_DIR})