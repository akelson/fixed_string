#ifndef STATIC_STRING_BASE_H
#define STATIC_STRING_BASE_H

#include <cstddef> // for size_t

class fixed_string_base
{
 public:
  typedef char * iterator;
  typedef const char * const_iterator;

  virtual fixed_string_base& operator= (const fixed_string_base &) = 0;
  virtual fixed_string_base& operator= (const char *) = 0;

  virtual iterator begin() = 0;
  virtual const_iterator begin() const = 0;
  virtual iterator end() = 0;
  virtual const_iterator end() const = 0;

  virtual const size_t size() const = 0;
  virtual const size_t max_size() const = 0;
  virtual void clear() = 0;
  virtual bool empty() const = 0;
  
  virtual char& operator[] (size_t pos) = 0;
  virtual const char& operator[] (size_t pos) const = 0;
  virtual const char *c_str() const = 0;

  virtual fixed_string_base& append(const fixed_string_base &) = 0;
  virtual fixed_string_base& append(const char *) = 0;
};

#endif  // STATIC_STRING_BASE_H
