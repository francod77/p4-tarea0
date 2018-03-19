
#include <iostream>
#include "B.h"

B::B(int b) : b(b){}

void B::print(){
    std::cout << "B: " << this->b << std::endl;

}