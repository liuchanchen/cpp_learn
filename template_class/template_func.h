#ifndef TEMPLATE_FUNC_H
#define TEMPLATE_FUNC_H
#include <iostream>
using namespace std;

template <typename tt>
int friend_template_func(tt &);

#if 1
template <typename t, int size>
class template_class
{
private:
  t items;

public:
  template_class(t num) : items(num) {}
  void normal_func(int);
  void temp_func(t, int);
  friend int friend_template_func<template_class<t, size>>(template_class<t, size> &);
  // friend int friend_template_func<>(template_class<t, size> &);
  friend int friend_func(template_class<t, size> &);
};
#endif
#if 0
template <typename t>
class template_class
{
  private:
    t items;

  public:
    template_class(t num) : items(num) {}
    void normal_func(int);
    void temp_func(t, int);
    friend int friend_template_func<template_class<t> >(template_class<t> &);
    // friend int friend_template_func<>(template_class<t, size> &);
};
#endif
#if 1
int friend_func(template_class<int, 32> &t_class)
{
  cout << t_class.items << endl;

  return 0;
}
#endif
template <typename tt>
int friend_template_func(tt &t_class)
{
  cout << "items:" << t_class.items << endl;
  cout << "type length:" << sizeof(tt) << endl;

  return 0;
}

#endif /* TEMPLATE_FUNC_H */
