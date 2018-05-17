#include "separate_namespace2.h"
#include <iostream>

namespace space_a
{
say_hello_again::say_hello_again()
{
    std::cout << "hello from space a again" << std::endl;
}
say_hello_again::~say_hello_again()
{
}
}
