#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

template <class Type, int n>
class array_template
{
  private:
    Type a[n];

  public:
    array_template(Type);
    ~array_template();
    Type operator[](const int);
    Type &operator[](const int);
};

template <class Type, int n>
array_template<Type, n>::array_template(Type init_value)
{
    cout << "array init" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i] = init_value;
    }
}

template <class Type, int n>
array_template<Type, n>::~array_template()
{
}

template <class Type, int n>
Type array_template<Type, n>::operator[](const int num)
{
}

template <class Type, int n>
Type &array_template<Type, n>::operator[](const int num)
{
}

#endif /* ARRAY_H */
