#include "separate_namespace1.h"
#include "separate_namespace2.h"
#include <iostream>

int main(int argc, char **agrv)
{
    space_a::say_hello hello_obj;
    space_a::say_hello_again hello_again_obj;

    return 0;
}