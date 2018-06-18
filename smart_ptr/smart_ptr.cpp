#include "smart_ptr.h"
#include <iostream>
#include <memory>

int cout_smart_ptr()
{
    std::shared_ptr<int> p = std::make_shared<int>(3);
    std::cout << "cout_smart_ptr: " << p.use_count() << std::endl;

    return 0;
}