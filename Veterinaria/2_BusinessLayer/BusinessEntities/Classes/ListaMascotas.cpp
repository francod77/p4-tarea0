//
// Created by juanr on 12/3/2018.
//

#include "ListaMascotas.h"
#include "Mascota.h"
#include "../../../Cross-Cutting/Const.h"

ListaMascotas::ListaMascotas(int length) {
    this->mascotas = new Mascota *[length];
    for (int i = 0; i < length; i++) {
        this->mascotas[i] = NULL;
    }
    this->length = 0;//Reserve el tamaño en memoria pero no tengo ningún objeto
};

ListaMascotas::~ListaMascotas() {
    for (int i = 0; i < this->length; ++i) {
        delete this->mascotas[i];
    }
    delete this->mascotas;
};

Mascota *ListaMascotas::get(int num) {
    return this->mascotas[num];
};

int ListaMascotas::getlength() {
    return this->length;
};

void ListaMascotas::add(Mascota *mascota) {
    this->mascotas[this->length] = mascota;
    this->length++;
};
