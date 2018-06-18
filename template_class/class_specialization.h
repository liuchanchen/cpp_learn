#ifndef CLASS_SPECIALIZATION_H
#define CLASS_SPECIALIZATION_H
#include <iostream>
using namespace std;

template <class t1, class t2, class t3>
class spec_class
{
  public:
    int method1(t1);
    int method2(t2);
    int method3(t3);
    t1 mem1;
    t2 mem2;
};

template <class t3>
class spec_class<int, int, t3>
{
  public:
    int method1(int);
    int method2(int);
    int method3(t3);
    int mem1;
    int mem2;
    t3 mem3;
};

template <class t1, class t2, class t3>
int spec_class<t1, t2, t3>::method1(t1 arg)
{
    cout << "implicate method1: " << arg << endl;

    return 0;
}

template <class t1, class t2, class t3>
int spec_class<t1, t2, t3>::method2(t2 arg)
{
    cout << "implicate method2: " << arg << endl;

    return 0;
}

template <class t1, class t2, class t3>
int spec_class<t1, t2, t3>::method3(t3 arg)
{
    cout << "implicate method3: " << arg << endl;

    return 0;
}

template <class t3>
int spec_class<int, int, t3>::method1(int arg)
{
    cout << "explicate method1: " << arg << endl;

    return 0;
}

template <class t3>
int spec_class<int, int, t3>::method2(int arg)
{
    cout << "explicate method2: " << arg << endl;

    return 0;
}

template <class t3>
int spec_class<int, int, t3>::method3(t3 arg)
{
    cout << "explicate method3: " << arg << endl;

    return 0;
}

#endif /* CLASS_SPECIALIZATION_H */
