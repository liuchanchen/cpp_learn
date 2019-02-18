#include "dynamic_cast_test.h"
#include <iostream>
#include <typeinfo>

class base_class
{
  private:
    /* data */
  public:
    virtual int method()
    {
        std::cout << "base class" << std::endl;
    }
};

class son_class : public base_class
{
  public:
    virtual int method()
    {
        std::cout << "son class" << std::endl;
    }
};

class grandson_class : public son_class
{
  public:
    virtual int method()
    {
        std::cout << "grandson class" << std::endl;
    }
};

bool dynamic_cast_test()
{
    //base_class *base_p = new base_class;//dynamic cast error
    base_class*base_p = new son_class;

    base_p->method();
    std::cout<<typeid(base_p).name()<<std::endl;
    std::cout<<typeid(*base_p).name()<<std::endl;
    son_class *son_p = dynamic_cast<son_class *>(base_p);
    if (0 == son_p)
    {
        std::cout << "cast error"
                  << " son_p" << std::endl;
    }
    else
    {
        son_p->method();
        grandson_class *grandson_p = dynamic_cast<grandson_class *>(son_p);
        if (0 == grandson_p)
        {
            std::cout << "cast error"
                      << " grandson_p" << std::endl;
        }
        else
        {
            grandson_p->method();
        }
    }

    return true;
}