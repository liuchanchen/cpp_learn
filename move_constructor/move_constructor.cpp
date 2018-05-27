#include "move_constructor.h"
#include <iostream>

using namespace std;

move_class::move_class()
{
    x = 10;
    std::cout << "entry default constructor" << endl;
}

move_class::move_class(class move_class &copy_class)
{

    std::cout << "entry copy constructor" << endl;
}

move_class::move_class(class move_class &&move_class)
{
    x = 20;
    std::cout << "entry move constructor" << endl;
}