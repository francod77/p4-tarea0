//
// Created by juanr on 12/3/2018.
//

#ifndef VETERINARIA_LISTMASCOTAS_H
#define VETERINARIA_LISTMASCOTAS_H


#include "Mascota.h"

class ListaMascotas {
private:
    Mascota** mascotas;
    int length;
public:
    ListaMascotas(int length);
    ~ListaMascotas();
    Mascota* get(int posicion);
    void add(Mascota* mascota);
};


#endif //VETERINARIA_LISTMASCOTAS_H
