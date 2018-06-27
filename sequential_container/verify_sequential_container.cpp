#include "verify_sequential_container.h"
#include <iostream>

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
class sequential_container_verification
{
  private:
    int elem_num;

  public:
    sequential_container_verification(int num) : elem_num(num){};
    //------------check sequentail container element location---------
    bool check_location(sequentail_container_type<T> &);
    //------------check sequentail container access time cost---------
    bool check_time_cost(sequentail_container_type<T> &);
    //------------check sequentail container member---------
    bool check_member(sequentail_container_type<T> &);
};

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
class sequential_container_verification<T, sequentail_container_type>::check_location(sequentail_container_type<T> &templ_container)
{

    return true;
}

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
class sequential_container_verification<T, sequentail_container_type>::check_location(sequentail_container_type<T> &container)
{
    return true;
}

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class sequentail_container_type>
class sequential_container_verification<T, sequentail_container_type>::check_location(sequentail_container_type<T> &container)
{
    return true;
}

bool
verify_sequential_container()
{
    return true;
}