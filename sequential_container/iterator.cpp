#include "iterator.h"
#include <iostream>
#include <vector>

int find_elem_in_vector()
{
    std::vector<int> vec_cp;
    int index = 0;
    int elem = 6;
    int total_elem_num = 8;

    container_test<int, std::vector> vec(vec_cp, total_elem_num);
    for (int i = 0; i < vec.get_max_elem_num(); i++)
    {
        vec.container.push_back(i);
    }
    std::cout << "container size:" << vec.container.size() << std::endl;
    bool result = vec.find_a_elem_in_contanier(vec.container, elem, index);
    if (true == result)
    {
        std::cout << "find result :" << index << std::endl;
    }
    else
    {
        std::cout << "find nothing" << std::endl;
    }

    return 0;
}

int find_elem_in_list()
{
    std::list<int> list_cp;
    int index = 0;
    int elem = 6;
    int total_elem_num = 16;

    container_test<int, std::list> lst(list_cp, total_elem_num);
    for (int i = 0; i < lst.get_max_elem_num(); i++)
    {
        lst.container.push_back(i);
    }
    std::cout << "container size:" << lst.container.size() << std::endl;
    bool result = lst.find_a_elem_in_contanier(lst.container, elem, index);
    if (true == result)
    {
        std::cout << "find result :" << index << std::endl;
    }
    else
    {
        std::cout << "find nothing" << std::endl;
    }

    return 0;
}

int find_elem_in_move_vector()
{
    std::vector<int> vec_move;
    int index = 0;
    int elem = 6;
    int total_elem_num = 8;
    container_test<int, std::vector> vec;

    //   container_test<int, std::vector> vec(vec_move, total_elem_num);
    for (int i = 0; i < total_elem_num; i++)
    {
        vec_move.push_back(i);
    }
    vec.container = std::move(vec_move);
    std::cout << "container size:" << vec.container.size() << std::endl;
    bool result = vec.find_a_elem_in_contanier(vec.container, elem, index);
    if (true == result)
    {
        std::cout << "find result :" << index << std::endl;
    }
    else
    {
        std::cout << "find nothing" << std::endl;
    }

    return 0;
}