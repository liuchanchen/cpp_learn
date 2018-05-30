#ifndef MOVIE_CONSTRUCTOR_H
#define MOVIE_CONSTRUCTOR_H

#include <iostream>

template <typename T>
class move_class
{
private:
  size_t size;
  // T *data;
  char *data;
#define COPY_CONS (1)
public:
  explicit move_class(int len) : size(len), data(nullptr)
  {
    std::cout << "original constructor size: " << size << std::endl;
    data = new T[size];
    std::cout << "allocate :" << std::hex << data << std::endl;
  }
#if COPY_CONS
  // copy constructor
  //move_class(class move_class<T> &other) : size(0), data(nullptr)
  move_class(class move_class<T> &other)
  {
    size = other.size;
    data = new T[size];
    //   data = new char[30];
    std::cout << "size: " << size << data << std::endl;
    std::cout << "allocate :" << std::hex << data << std::endl;
    std::copy(other.data, other.data + other.size, data);
  }
#else
  //move constructor
  move_class(class move_class<T> &&other) : size(0), data(nullptr)
  {
    std::cout << "entry move constructor" << std::endl;
    size = other.size;
    data = other.data;
    other.size = 0;
    other.data = nullptr;
  }
#endif
  ~move_class()
  {
    size = 0;
    delete[] data;
  }
};

extern int compare_move_copy();
extern int vector_ops();

#endif /* MOVIE_CONSTRUCTOR_H */
