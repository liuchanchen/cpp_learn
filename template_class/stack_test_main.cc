#include "stack_test_main.h"
#include "stack.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

static int stack_double_test(stack_template<double> &stack);
static int stack_string_test(stack_template<string> &stack);
static int stack_int_test(stack_template<int> &stack);
int main(int argc, char **argv)
{
    stack_template<int> stack_int(24);
    stack_template<double> stack_double(24);
    stack_template<string> stack_string(24);

    cout << "stack_int addr :" << &stack_int << endl;
    stack_int_test(stack_int);
    stack_double_test(stack_double);
    stack_string_test(stack_string);
    cout << "main exit" << endl;

    return 0;
}
static int stack_double_test(stack_template<double> &stack)
{
    double a[16] = {0.0};
    int i = 0, temp = 0;

    cout << "stack addr" << &stack << endl;
    for (i = 0; i < 16; i++)
    {
        a[i] = (double)i;
        stack.push(a[i]);
    }
    stack.show_cur_stack_deepth();

    return 0;
}
static int stack_int_test(stack_template<int> &stack)
{
    int a[16] = {0};
    int i = 0, temp = 0;

    cout << "stack addr" << &stack << endl;
    for (i = 0; i < 16; i++)
    {
        a[i] = i;
        stack.push(a[i]);
    }
    stack.show_cur_stack_deepth();

    return 0;
}

#if 1
static int stack_string_test(stack_template<string> &stack)
{
    string a[16];
    char temp_char[32] = {0};
    int i = 0, temp = 0;

    for (i = 0; i < 16; i++)
    {
        memset(temp_char, 0x0, sizeof(temp_char));
        sprintf(temp_char, "%d", i);
        a[i] = temp_char;
        stack.push(a[i]);
    }
    stack.show_cur_stack_deepth();

    return 0;
}
#endif