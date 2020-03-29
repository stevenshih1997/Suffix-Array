include_directories(
  ${CMAKE_SOURCE_DIR}/suffix
)
add_executable(SuffixTest SuffixTest.cpp)
add_executable(NormalTest NormalTest.cpp)
add_executable(RadixTest RadixTest.cpp)
