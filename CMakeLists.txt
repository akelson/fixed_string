cmake_minimum_required (VERSION 3.0)

include_directories(${GTEST_INCLUDE_DIRS})

find_package(GTest REQUIRED)

add_executable(
  runTest
  test.cpp
  )

target_link_libraries(runTest ${GTEST_LIBRARIES} pthread)

target_compile_options(
  runTest PRIVATE -Werror -Wall
  )
