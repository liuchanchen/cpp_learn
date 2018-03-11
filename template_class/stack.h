#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class Type>
class stack_template
{
  private:
    int stack_deepth;
    Type *items;
    int top;

  public:
    stack_template(int);
    ~stack_template();
    int push(Type);
    int pop(Type);
    int show_cur_stack_deepth();
    bool isfull();
    bool isempty();
    int del_mem();
    stack_template &operator=(const stack_template &);
};

template <class Type>
stack_template<Type>::stack_template(int stack_size) : stack_deepth(stack_size)
{
    cout << "constructor" << this << endl;
    top = 0;
    items = new Type[stack_deepth];
    cout << "new items" << items << endl;
    cout << "stack_deepth" << stack_deepth << endl;
}

template <class Type>
stack_template<Type>::~stack_template()
{
    cout << "disconstructor: " << items << endl;
    delete[] items;
}

template <class Type>
int stack_template<Type>::del_mem()
{
    cout << "del mem: " << items << endl;
    delete[] items;
    cout << "del successfully" << endl;
}
template <class Type>
int stack_template<Type>::push(Type item)
{
    if (true == isfull())
    {
        cout << "stack is full " << endl;
        return -1;
    }
    items[top] = item;
    cout << "items value  " << items[top] << endl;
    cout << "item  value  " << item << endl;
    top++;

    return 0;
}
template <class Type>
int stack_template<Type>::pop(Type item)
{
    if (true == isempty())
    {
        return -1;
    }
    item = items[top];
    top--;

    return 0;
}

template <class Type>
bool stack_template<Type>::isfull()
{
    if (top == stack_deepth)
    {
        return true;
    }
    return false;
}

template <class Type>
bool stack_template<Type>::isempty()
{
    if (top == 0)
    {
        return true;
    }
    return false;
}
template <class Type>
int stack_template<Type>::show_cur_stack_deepth()
{
    cout << "current stack deepth:" << top << endl;
    return 0;
}
template <class Type>
stack_template<Type> &stack_template<Type>::operator=(const stack_template<Type> &stack)
{
    cout << "entry operator" << endl;
    if (&stack == this)
    {
        return *this;
    }
    if (items != 0)
    {
        delete[] items;
    }
    stack_deepth = stack.stack_deepth;
    top = stack.top;
    items = new Type[stack_deepth];
    for (int i = 0; i < top; i++)
    {
        items[i] = stack.items[i];
    }

    return *this;
}
#endif /* STACK_H */
