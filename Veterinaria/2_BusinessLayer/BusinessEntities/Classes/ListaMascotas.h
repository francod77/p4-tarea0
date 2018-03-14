//
// Created by juanr on 12/3/2018.
//

#ifndef VETERINARIA_LISTMASCOTAS_H
#define VETERINARIA_LISTMASCOTAS_H


#include "Mascota.h"
#include "../../../Cross-Cutting/DataTypes/DataMascota.h"

class ListaMascotas {
private:
    Mascota** mascotas;
    int length;
public:
    ListaMascotas(int length);
    ~ListaMascotas();
    Mascota* get(int num);
    int getlength();
    DataMascota* getmascota(int);
    void add(Mascota* mascota);
};


#endif //VETERINARIA_LISTMASCOTAS_H
