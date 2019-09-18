#include "smart_ptr.h"
#include <iostream>
#include <memory>

std::shared_ptr<int> g_ptr;

static int sub_func(std::shared_ptr<int> p)
{
    std::cout << "sub_func ref counter: " << p.use_count() << std::endl;

    return 0;
}

static int sub_common_func(std::shared_ptr<int> p)
{
    *p = *p + 1;

    return 0;
}

int cout_smart_ptr()
{
    std::shared_ptr<int> p = std::make_shared<int>(3);
    std::cout << "cout_smart_ptr: " << p.use_count() << std::endl;
    std::shared_ptr<int> arr_ptr = std::make_shared<int>(3);
    std::cout << "ptr val " << (int)*arr_ptr << std::endl;

    return 0;
}

template <typename T>
void deleter(T *p)
{
    std::cout << "invoke deleter" << std::endl;
    delete[] p;
}

int array_ptr()
{
    g_ptr = std::make_shared<int>(0);
    int count = 10;
    for (int i = 0; i < count; i++)
    {
        sub_func(g_ptr);
        sub_common_func(g_ptr);
    }
    std::cout << "ptr val " << (int)*g_ptr << std::endl;

    return 0;
}

int free_ptr()
{
    int *common_p = new int[32];
    std::shared_ptr<int> p(common_p, deleter<int>);
    std::cout << "cout_smart_ptr: " << p.use_count() << std::endl;
    sub_func(p);
    p.reset();
    std::cout << "cout_smart_ptr: " << p.use_count() << std::endl;

    return 0;
}
