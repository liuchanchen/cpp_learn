#include "separate_namespace1.h"
#include <iostream>

namespace space_a
{
say_hello::say_hello()
{
    std::cout << "hello from space a" << std::endl;
}
say_hello::~say_hello()
{
}
}
