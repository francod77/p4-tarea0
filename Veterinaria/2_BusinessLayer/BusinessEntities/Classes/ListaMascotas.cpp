//
// Created by juanr on 12/3/2018.
//

#include "ListaMascotas.h"
#include "Mascota.h"
#include "../../../Cross-Cutting/Const.h"

ListaMascotas::ListaMascotas() {
    this->mascotas = new Mascota* [MAX_MASCOTAS];
    for (int i = 0; i < MAX_MASCOTAS; i++) {
        this->mascotas[i] = nullptr;
    }
    this->length = 0;//Reserve el tamaño en memoria pero no tengo ningún objeto
};

ListaMascotas::~ListaMascotas() {
    //aca capaz que en vez de length va MAX_MASCOTAS
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

void ListaMascotas::add( Mascota *mascota) {
    this->mascotas[this->length] =  mascota ;
    this->length++;
};
