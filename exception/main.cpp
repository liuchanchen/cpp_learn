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

int main(int argc, char **argv)
{
    my_excption my_excep;

    test_my_exception();

    return 0;
}