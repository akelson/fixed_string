#ifndef STATIC_STRING_H
#define STATIC_STRING_H

#include <string.h>

#include "fixed_string_base.h"

template <size_t MAX_SIZE>
class fixed_string : public fixed_string_base
{
 public:
  
  // Default Constructor
  fixed_string() : str_() {}

  // Constructor
  fixed_string(const char *str) : str_()
  {
    strncpy(str_, str, MAX_SIZE);
  }

  // Constructor
  template <size_t OTHER_MAX_SIZE>
  fixed_string(const fixed_string<OTHER_MAX_SIZE> str) : str_()
  {
    strncpy(str_, str.str_, MAX_SIZE);
  }

  // Copy-Assign
  virtual fixed_string_base& operator= (const fixed_string_base &str)
  {
    return operator =(str.c_str());
  }

  // Assign
  virtual fixed_string_base& operator= (const char *str)
  {
    strncpy(str_, str, MAX_SIZE);
    str_[MAX_SIZE + 1] = '\0';
    return *this;
  }

  virtual iterator begin()
  {
    return str_;
  }

  virtual const_iterator begin() const
  {
    return str_;
  }

  virtual iterator end()
  {
    return str_ + size();
  }

  virtual const_iterator end() const
  {
    return str_ + size();
  }

  virtual const size_t size() const
  {
    return strlen(str_);
  }

  virtual const size_t max_size() const
  {
    return MAX_SIZE;
  }

  virtual void clear()
  {
    str_[0] = '\0';
  }

  virtual bool empty() const
  {
    return '\0' == str_[0];
  }

  virtual char& operator[] (size_t pos)
  {
    return str_[pos];
  }

  virtual const char& operator[] (size_t pos) const
  {
    return str_[pos];
  }

  virtual fixed_string_base& append(const fixed_string_base &str)
  {
    return append(str.c_str());
  }

  virtual fixed_string_base& append(const char *str)
  {
    const size_t size_remain = MAX_SIZE - size();
    strncat(str_, str, size_remain);
    return *this;
  }

  virtual const char *c_str() const
  {
    return str_;
  }

  fixed_string<MAX_SIZE> substr(size_t pos, size_t len) const
  {
    fixed_string<MAX_SIZE> result;
    memcpy(result.str_, &str_[pos], len);
    return result;
  }

  char str_[MAX_SIZE + 1];
};

template <size_t N1, size_t N2>
fixed_string<N1 + N2 + 1> operator+ (const fixed_string<N1> &lhs,
                                      const fixed_string<N2> &rhs)
{
  fixed_string<N1 + N2 + 1> result(lhs);
  strcat(result.str_, rhs.str_);
  return result;
}

#endif  // STATIC_STRING_H
