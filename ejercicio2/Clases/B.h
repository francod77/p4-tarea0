

#ifndef EJERCICIO2_B_H
#define EJERCICIO2_B_H

class A;
#include "C.h"

class B {
private:
    int b;
    A *unA;
    C *unC;
public:
    B(int);
    void print();
};

#include "A.h"
#endif //EJERCICIO2_B_H
