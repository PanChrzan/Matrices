cmake_minimum_required(VERSION 3.10)
project(Matrices)

set(LOGIC_FILES
    sources/Matrix.cpp
)
add_library(logic ${LOGIC_FILES})

set(TEST_SOURCE_FILES
    tests/main.cpp
    tests/test_Matrix.cpp
)

# program
add_executable(program main.cpp)
target_link_libraries(program logic)

# tests
set(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../libs/googletest)
# set(TEST_SOURCES  ${TEST_SOURCE_FILES})

add_executable(test_program ${TEST_SOURCE_FILES})
set(GTEST_INCLUDE_DIR PUBLIC ${GTEST_DIR}/googletest/include)
target_include_directories(test_program ${GTEST_INCLUDE_DIR})

target_link_libraries(test_program ${GTEST_DIR}/build/lib/libgtest.dll.a)
target_link_libraries(test_program logic)