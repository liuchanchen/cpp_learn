#include "move_constructor.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    move_class origin;

    cout << "origin.x: " << origin.x << endl;
    move_class copy(origin);
    cout << "copy.x: " << copy.x << endl;
    move_class move_obj = std::move(origin);
    cout << "move_obj.x: " << move_obj.x << endl;

    return 0;
}
