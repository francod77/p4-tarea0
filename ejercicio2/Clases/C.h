

#ifndef EJERCICIO2_C_H
#define EJERCICIO2_C_H

class A;
class B;

class C {
private:
    int c;
    A *unA;
    B *unb;
public:
    C(int);
    void print();
};

#include "A.h"
#include "B.h"
#endif //EJERCICIO2_C_H
