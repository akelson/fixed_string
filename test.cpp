#include "static_string.h"

#include <gtest/gtest.h>

TEST(StaticStringTest, Constructor_1)
{
  static_string<10> s;
  EXPECT_STREQ(s.str_, "");
}

TEST(StaticStringTest, Constructor_1_1)
{
  static_string<0> s;
  EXPECT_STREQ(s.str_, "");
}

TEST(StaticStringTest, Constructor_2)
{
  static_string<20> s("Hello, World!");
  EXPECT_STREQ(s.str_, "Hello, World!");
}

TEST(StaticStringTest, Constructor_2_1)
{
  static_string<0> s("Hello, World!");
  EXPECT_STREQ(s.str_, "");
}

TEST(StaticStringTest, Constructor_2_2)
{
  static_string<1> s("Hello, World!");
  EXPECT_STREQ(s.str_, "H");
}

TEST(StaticStringTest, Constructor_3)
{
  static_string<20> s1("Hello, World!");
  static_string<30> s2(s1);
  EXPECT_STREQ(s2.str_, "Hello, World!");
}

TEST(StaticStringTest, Constructor_3_1)
{
  static_string<20> s1("Hello, World!");
  static_string<0> s2(s1);
  EXPECT_STREQ(s2.str_, "");
}

TEST(StaticStringTest, Constructor_3_2)
{
  static_string<20> s1("Hello, World!");
  static_string<1> s2(s1);
  EXPECT_STREQ(s2.str_, "H");
}

TEST(StaticStringTest, CopyAssign_1)
{
  static_string<30> s1;
  static_string<20> s2("Hello, World!");
  s1 = s2;
  EXPECT_STREQ(s1.str_, "Hello, World!");
}

TEST(StaticStringTest, CopyAssign_1_1)
{
  static_string<0> s1;
  static_string<20> s2("Hello, World!");
  s1 = s2;
  EXPECT_STREQ(s1.str_, "");
}

TEST(StaticStringTest, CopyAssign_1_2)
{
  static_string<1> s1;
  static_string<20> s2("Hello, World!");
  s1 = s2;
  EXPECT_STREQ(s1.str_, "H");
}

TEST(StaticStringTest, Assign_1)
{
  static_string<20> s;
  s = "Hello, World!";
  EXPECT_STREQ(s.str_, "Hello, World!");
}

TEST(StaticStringTest, Assign_1_1)
{
  static_string<0> s;
  s = "Hello, World!";
  EXPECT_STREQ(s.str_, "");
}

TEST(StaticStringTest, Assign_1_2)
{
  static_string<1> s;
  s = "Hello, World!";
  EXPECT_STREQ(s.str_, "H");
}

TEST(StaticStringTest, begin_1)
{
  static_string<20> s("Hello, World!");
  EXPECT_EQ(s.str_, s.begin());
}

TEST(StaticStringTest, begin_2)
{
  const static_string<20> s("Hello, World!");
  EXPECT_EQ(s.str_, s.begin());
}

TEST(StaticStringTest, end_1)
{
  static_string<20> s("01234");
  EXPECT_EQ(s.str_ + 5 , s.end());
  EXPECT_EQ('\0', *s.end());
}

TEST(StaticStringTest, end_2)
{
  const static_string<20> s("01234");
  EXPECT_EQ(s.str_ + 5 , s.end());
  EXPECT_EQ('\0', *s.end());
}

TEST(StaticStringTest, size)
{
  const static_string<20> s("12345");
  EXPECT_EQ(5 , s.size());
}

TEST(StaticStringTest, size_1)
{
  const static_string<5> s("12345");
  EXPECT_EQ(5 , s.size());
}

TEST(StaticStringTest, size_2)
{
  const static_string<0> s("12345");
  EXPECT_EQ(0 , s.size());
}

TEST(StaticStringTest, size_3)
{
  const static_string<100> s("");
  EXPECT_EQ(0 , s.size());
}

TEST(StaticStringTest, max_size)
{
  const static_string<100> s("Hello, World!");
  EXPECT_EQ(100 , s.max_size());
}

TEST(StaticStringTest, clear)
{
  static_string<100> s("Hello, World!");
  s.clear();
  EXPECT_STREQ(s.str_, "");
}

TEST(StaticStringTest, empty)
{
  const static_string<100> s("Hello, World!");
  EXPECT_FALSE(s.empty());
}

TEST(StaticStringTest, empty_1)
{
  const static_string<100> s;
  EXPECT_TRUE(s.empty());
}

TEST(StaticStringTest, operator_index_1)
{
  static_string<100> s("012345");
  EXPECT_EQ(s[0], '0');
  EXPECT_EQ(s[3], '3');
  s[1] = 'x';
  EXPECT_EQ(s[1], 'x');
}

TEST(StaticStringTest, operator_index_2)
{
  const static_string<100> s("012345");
  EXPECT_EQ(s[0], '0');
  EXPECT_EQ(s[3], '3');
}

TEST(StaticStringTest, append_1)
{
  static_string<100> s1("Hello, ");
  const static_string<50> s2("World!");
  s1.append(s2);
  EXPECT_STREQ(s1.str_, "Hello, World!");
}

TEST(StaticStringTest, append_2)
{
  static_string<100> s1("Hello, ");
  s1.append("World!");
  EXPECT_STREQ(s1.str_, "Hello, World!");
}

TEST(StaticStringTest, append_3)
{
  static_string<100> s1("a");
  s1.append("b")
    .append("c");
  EXPECT_STREQ(s1.str_, "abc");
}

TEST(StaticStringTest, append_4)
{
    static_string<20> s("a");
    s.append("b").append(static_string<10>("c"));
  EXPECT_STREQ("abc", s.str_);
}

TEST(StaticStringTest, append_5)
{
  static_string<5> s;

  s.append("...");
  s.append("...");
  s.append("...");
  s.append("...");

  EXPECT_STREQ(".....", s.str_);
}

TEST(StaticStringTest, stubstr_1)
{
  const static_string<100> s("0123456");
  EXPECT_STREQ("23", s.substr(2, 2).str_);
}

TEST(StaticStringTest, operator_plus_1)
{
  const static_string<5> s1("aaaaa");
  const static_string<4> s2("bbbb");
  static_string<100> s3 = s1 + s2;
  EXPECT_STREQ("aaaaabbbb", s3.str_);
}

void myCat(static_string_base *dest, 
           const static_string_base &s1, 
           const static_string_base &s2)
{
  (*dest).append(s1).append(s2);
}

TEST(StaticStringTest, base_1)
{
  static_string<100> s;
  myCat( &s,
      static_string<10>("Hello,"),
      static_string<20>(" World!"));
  EXPECT_STREQ(s.str_, "Hello, World!");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
