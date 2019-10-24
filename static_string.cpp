#include <iostream>

#include "static_string.h"

int main()
{
  static_string<10> s1("Hello ");
  static_string<10> s2("World!");
  static_string<100> s3;

  s3.append(s1)
    .append(s2);

  std::cout << (s1 + s2).c_str() << std::endl;
  std::cout << s3.c_str() << std::endl;
}
