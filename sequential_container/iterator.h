#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include <list>
#include <vector>

//template <typename T, class<typename T1> Templ_class>
//template <template <typename T1> class Templ_class, typename T>
template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class Templ_class>
class container_test
{
  private:
    int max_elem_num = 16;

  public:
    container_test();
    container_test(Templ_class<T> &, int);
    //Templ_class<T> container;
    Templ_class<T> container;
    bool find_a_elem_in_contanier(Templ_class<T>, T, int &);
    int get_max_elem_num() { return max_elem_num; }
};

template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class Templ_class>
//template <typename T, class Templ_class>
container_test<T, Templ_class>::container_test()
{
}

//template <template <typename T1> class Templ_class, typename T>
template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class Templ_class>
//template <typename T, class Templ_class>
container_test<T, Templ_class>::container_test(Templ_class<T> &cont, int max_num) : max_elem_num(max_num)
{
    std::cout << __FUNCTION__ << " " << max_elem_num << std::endl;
    container = cont;

    return;
}

//template <template <typename T1> class Templ_class, typename T>
template <typename T, template <typename T1, typename _Allocator = std::allocator<T1>> class Templ_class>
//template <typename T, class Templ_class>
bool container_test<T, Templ_class>::find_a_elem_in_contanier(Templ_class<T> templ_containter, T elem, int &index)
{
    bool ret = false;
    typename Templ_class<T>::iterator iter;
    int count = 0;

    for (iter = container.begin(); iter != container.end(); iter++)
    {
        if (*iter == elem)
        {
            index = count;
            return true;
        }
        count++;
    }

    return ret;
}

extern int find_elem_in_vector();
extern int find_elem_in_list();
extern int find_elem_in_move_vector();
#endif /* ITERATOR_H */
