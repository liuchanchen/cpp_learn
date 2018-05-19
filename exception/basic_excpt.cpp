#include <exception>
#include <iostream>

class my_excption : public exception
{
  public:
    my_excption(void);
    virtual ~my_excption();
};

my_excption::my_excption()
{
    std::cout << "entry my_excption" << std::endl;
}

const char *my_excption::what()
{
    std::cout << "my_excption caught" << std::endl;
}
