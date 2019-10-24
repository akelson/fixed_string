cmake_minimum_required (VERSION 3.0)

add_executable(
  static_string
  static_string.cpp
  )

target_compile_options(
  static_string PRIVATE -Werror -Wall
  )
