#include "iostream"
#include "lvaue.h"

int main(int agrc, char **argv)
{
    int arg = 10;
    std::cout << "arg to be passed addr: " << &arg << std::endl;
    pass_arg(arg);
    normal_pass_arg(arg);

    return 0;
}