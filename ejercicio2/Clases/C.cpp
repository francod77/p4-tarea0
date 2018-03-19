
#include <iostream>
#include "C.h"

C::C(int c) : c(c){}

void C::print(){
    std::cout << "C: " << this->c << std::endl;

}