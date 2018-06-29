#include "verify_sequential_container.h"
#include <iostream>

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
class sequential_container_verification
{
  private:
    sequentail_container_type<T> templ_container;

  public:
    sequential_container_verification(int);
    //------------check sequentail container element location---------
    bool check_location();
    //------------check sequentail container access time cost---------
    bool check_time_cost();
    //------------check sequentail container member---------
    bool check_member();
};

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
sequential_container_verification<T, sequentail_container_type>::sequential_container_verification(int num){};

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
bool sequential_container_verification<T, sequentail_container_type>::check_location()
{
    int size = templ_container.size();
    auto iter = templ_container.begin();

    std::cout << "---------print address------------" << std::endl;
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
    return true;
}