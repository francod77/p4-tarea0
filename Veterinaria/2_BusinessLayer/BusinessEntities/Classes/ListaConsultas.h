//
// Created by juanr on 12/3/2018.
//

#ifndef VETERINARIA_LISTCONSULTAS_H
#define VETERINARIA_LISTCONSULTAS_H


#include "Consulta.h"

class ListaConsultas {
private:
    Consulta **consultas;
    int length;
public:
    ListaConsultas(int length);

    ~ListaConsultas();

    Consulta *get(int num);

    void add(Consulta *consulta);

    int getlength();
};


#endif //VETERINARIA_LISTCONSULTAS_H
