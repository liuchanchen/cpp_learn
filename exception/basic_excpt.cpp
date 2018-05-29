#include "basic_excpt.h"
#include <iostream>

my_excption::my_excption()
{
    std::cout << "entry my_excption" << std::endl;
}

my_excption::~my_excption() throw()
{
}

const char *my_excption::what()
{
    return "my_excption caught";
}

int my_excption::test_no_except(int arg) NOEXCEP_FLAG
{
    return 0;
}

int my_excption::test_no_except() NOEXCEP_FLAG
{
    exception err;

    std::cout << "test_no_except" << std::endl;
    throw err;

    return 0;
}

int override_func(void)
{
    return 0;
}

int override_func(int)
{
    return 0;
}