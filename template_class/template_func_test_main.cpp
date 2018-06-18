#include "template_func.h"

int main(int argc, char **argv)
{
    template_class<int, 32> template_a(22423);
    //template_class<int> template_a(22423);
    friend_template_func(template_a);
    friend_func(template_a);

    return 0;
}