
#include <iostream>
#include "A.h"

A::A(int a) : a(a){}

void A::print(){
    std::cout << "A: " << this->a << std::endl;

}
