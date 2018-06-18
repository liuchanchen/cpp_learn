#include "class_specialization.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    spec_class<double, char, int> implicate_class;
    spec_class<int, int, float> explicate_class;

    implicate_class.method1(3.2);
    implicate_class.method2('f');
    implicate_class.method3(2562);
    explicate_class.method1(2214);
    explicate_class.method2(22312);
    explicate_class.method3(256.2);

    return 0;
}