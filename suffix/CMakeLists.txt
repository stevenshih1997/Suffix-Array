cmake_minimum_required(VERSION 3.10)

# set the project name
project(suffix)

# set flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(suffix)
add_subdirectory(suffix/test)

# add support for testing
enable_testing()
add_test(NAME Runs COMMAND suffix)
add_test(NAME SuffixTest COMMAND SuffixTest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/suffix/test)
add_test(NAME NormalTest COMMAND NormalTest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/suffix/test)
add_test(NAME RadixTest COMMAND RadixTest WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/suffix/test)

