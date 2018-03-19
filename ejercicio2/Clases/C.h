

#ifndef EJERCICIO2_C_H
#define EJERCICIO2_C_H

#include "B.h"
#include "A.h"

class C {
private:
    int c;
    A claseA;
    B claseB
public:
    C();
    ~C();
    A getA();
    B getB();
    int get();
    void set(int num);
    void print();
};


#endif //P4_TAREA0_EJ2_C_H
