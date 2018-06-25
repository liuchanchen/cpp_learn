#include "initialize_list.h"
#include <algorithm>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <iterator>

template <typename T>
static bool initialize_func(std::initializer_list<T> arg);
template <typename T>
void show(const T &elem);

template <typename T>
void show(const T &elem)
{
    std::cout << elem << std::endl;
}

void show_char(const char &elem)
{
    std::cout << elem << std::endl;
}

template <typename T>
static bool initialize_func(std::initializer_list<T> arg)
{
    std::cout << "---------reverse by for-------------" << std::endl;
    for (auto elem : arg)
    {
        std::cout << elem << std::endl;
    }
    std::cout << "---------reverse by for_each-------------" << std::endl;
    //   std::iterator<T> elem1;
    //std::cout << " show<T>: " << show<T> << std::endl;
    //   for_each(arg.begin(); arg.end(); show<T>);
    std::for_each(arg.begin(), arg.end(), show<T>);
    //std::for_each(arg.begin(), arg.end(), show_char);
    //std::for_each(arg.begin(), arg.end(), [](const T &elem) { std::cout << elem << std::endl; });

    return true;
}

int32_t test_initialize_list()
{
    initialize_func<int32_t>({1, 2, 3, 4, 5, 6});
    initialize_func<char>({1, 2, 3, 4, 5, 6});

    return 0;
}