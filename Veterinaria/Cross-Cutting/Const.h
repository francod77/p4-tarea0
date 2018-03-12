//
// Created by juanr on 12/3/2018.
//

#ifndef VETERINARIA_CONST_H
#define VETERINARIA_CONST_H


static class Const {
public:
    static int MAX_SOCIOS = 1000;
    static int MIN_MASCOTAS = 1;
    static int MAX_MASCOTAS = 10;
    static float FACTOR_ALIMENTO_GATO = 0.015;
    static float FACTOR_ALIMENTO_PERRO = 0.025;

    Const();

    virtual ~Const();
};


#endif //VETERINARIA_CONST_H
