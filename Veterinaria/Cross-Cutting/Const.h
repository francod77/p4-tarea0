//
// Created by juanr on 12/3/2018.
//

#ifndef VETERINARIA_CONST_H
#define VETERINARIA_CONST_H


class Const {
public:
    int MAX_SOCIOS = 1000;
    int MIN_MASCOTAS = 1;
    int MAX_MASCOTAS = 10;
    float FACTOR_ALIMENTO_GATO = 0.015;
    float FACTOR_ALIMENTO_PERRO = 0.025;
    int MAX_CONSULTAS = 10000;

    Const();

    virtual ~Const();
};


#endif //VETERINARIA_CONST_H
