#ifndef STACK_H
#define STACK_H

template <class Type>
class stack_template
{
  private:
    int stack_deepth;
    Type *items;
    int top;

  public:
    stack_template();
    ~stack_template();
    int push(Type);
    int pop(Type);
};

template <class Type>
stack_template<Type>::stack_template()
{
}

template <class Type>
int stack_template<Type>::push(Type)
{

    return 0;
}
template <class Type>
int stack_template<Type>::pop(Type)
{
    return 0;
}
#endif /* STACK_H */
