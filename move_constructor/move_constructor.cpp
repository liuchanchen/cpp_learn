#include "move_constructor.h"
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

int compare_move_copy()
{
    move_class<char> origin_1(30);

    move_class<char> copy_obj(origin_1);
    //  move_class<char> move_obj = std::move(origin_1);

    return 0;
}

int vector_ops()
{
    // Create a vector object and add a few elements to it.
    vector<move_class<char>>;
    //    v.push_back(move_class(25));
    //    v.push_back(MemoryBlock(75));
    //
    //    // Insert a new element into the second position of the vector.
    //    v.insert(v.begin() + 1, MemoryBlock(50));

    return 0;
}