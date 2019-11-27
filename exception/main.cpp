#include "basic_excpt.h"
#include <iostream>

using namespace std;

static int test_my_exception(void)
{
    my_excption err;
    int int_err;

    try
    {
        throw int_err;
        // throw err;
    }
    catch (my_excption &err)
    {
        cout << "exception captured" << endl;
    }

    return 0;
}

static int test_no_catch_exception(void)
{
    my_excption my_excep;
    my_excep.test_no_except();
    while(1);

    return 0;
}

int main(int argc, char **argv)
{
    my_excption my_excep;
    exception std_excep;

    try
    {
        my_excep.test_no_except();
    }
    catch (exception std_excep)
    {
        cout << "exception captured" << endl;
    }
    test_no_catch_exception();
    //   test_my_exception();

    return 0;
}