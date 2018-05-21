#ifndef BASIC_EXCPT_H
#define BASIC_EXCPT_H

#include <exception>
#include <iostream>

//#define NOEXCEP_FLAG std::noexcept
//#define NOEXCEP_FLAG throw()
#define NOEXCEP_FLAG

class my_excption : public std::exception
{
public:
  my_excption(void);
  int test_no_except() NOEXCEP_FLAG;
  virtual ~my_excption() throw();
  virtual const char *what();
};

#endif /* BASIC_EXCPT_H */