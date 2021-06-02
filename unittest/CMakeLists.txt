cmake_minimum_required(VERSION 3.10)
project(hypocalc_unittest)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories(..)
include_directories(../googletest/googletest/include)
link_directories(../googletest/lib)

enable_testing()

add_executable(
  hypocalc_unittest.app

  # Test framework
  testmain.cpp
  testcalculator.cpp
  
  # System under test
  ../hypocalculator.cpp
  ../triangledata.cpp
)

target_link_libraries(
  hypocalc_unittest.app
  gtest
  gtest_main
  pthread
)

include(GoogleTest)
# TODO:
# gtest_discover_tests(hypocalc_unittest)

