#include "lvaue.h"
#include <iostream>

int pass_arg(int &arg)
{
    std::cout << "arg value:" << arg << " arg addr:" << &arg << std::endl;

    return 0;
}

int normal_pass_arg(int arg)
{
    std::cout << "arg value:" << arg << " arg addr:" << &arg << std::endl;

    return 0;
}