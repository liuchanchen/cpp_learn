#include "verify_sequential_container.h"
#include <cstdint>
#include <iostream>
#include <list>
#include <vector>

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
class sequential_container_verification
{
  private:
    int elem_num;
    sequentail_container_type<T> templ_container;

  public:
    sequential_container_verification(int, std::initializer_list<T>);
    //------------check sequentail container element location---------
    bool check_location();
    //------------check sequentail container access time cost---------
    bool check_time_cost();
    //------------check sequentail container member---------
    bool check_member();
};

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
sequential_container_verification<T, sequentail_container_type>::sequential_container_verification(int num, std::initializer_list<T> arg) : elem_num(num)
{
    for (auto elem : arg)
    {
        templ_container.push_back(elem);
    }
};

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
bool sequential_container_verification<T, sequentail_container_type>::check_location()
{
    int size = templ_container.size();
    auto iter = templ_container.begin();

    std::cout << "---------print address----" << size << "--------" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << "num:" << i << "address:" << &iter[i] << " " << std::endl;
    }

    return true;
}

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
bool sequential_container_verification<T, sequentail_container_type>::check_time_cost()
{
    return true;
}

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
bool sequential_container_verification<T, sequentail_container_type>::check_member()
{
    return true;
}

bool verify::verify_sequential_container()
{
    int32_t container_size = 8;
    std::initializer_list<int32_t> arg = {1, 2, 3, 4, 5, 6, 7, 8};

    sequential_container_verification<int, std::vector> test_container_vec(container_size, arg);
    test_container_vec.check_location();
    sequential_container_verification<int, std::list> test_container_list(container_size, arg);
    //test_container_list.check_location();

    return true;
}