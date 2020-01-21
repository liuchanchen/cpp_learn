#include <iostream>

class rvo_class {
public:
    rvo_class() {
        std::cout << "entry constructor" << std::endl;
    }
    void print() { 
        std::cout << "print message" << std::endl;
    }
};

extern rvo_class rvo_case();