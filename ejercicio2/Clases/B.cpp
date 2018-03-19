
#include <iostream>
#include "B.h"

void A::set(int num) {
a=num;
}

int A::get() {
    return a;
}

void A::print() {
 std::cout<< "A" << a<< std::endl;

}

C A::getC() {
    return claseC;
}

B A::getB() {
    return claseB;
}

int A::geta() {
    return 0;
}

A::A() : claseB(A()) {

}

A::A(int num, B assB, C assC) : claseB(A()) {
a=num; claseB=assB; claseC=assC;
}
