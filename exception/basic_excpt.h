#ifndef BASIC_EXCPT_H
#define BASIC_EXCPT_H

#include <exception>

class my_excption : public std::exception
{
  public:
    my_excption(void);
    virtual ~my_excption() throw();
    virtual const char *what();
};

#endif /* BASIC_EXCPT_H */
