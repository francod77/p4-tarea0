#ifndef EJERCICIO2_A_H
#define EJERCICIO2_A_H

#include "B.h"
#include "C.h"

class A {
private:
    int a;
    B *unB;
    C *unC;
public:
    A();
    A(int,B,C);
    int geta();
    B getB();
    C getC();
    void set(int a);
    void print();
};


#endif //EJERCICIO2_A_H
