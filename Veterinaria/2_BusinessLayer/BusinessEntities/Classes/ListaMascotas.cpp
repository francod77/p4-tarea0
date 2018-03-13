//
// Created by juanr on 12/3/2018.
//

#include "ListaMascotas.h"
#include "Mascota.h"

ListaMascotas::ListaMascotas(int length){
    this->mascotas = new Mascota*[length];
    this->length = 0;//Reserve el tamaño en memoria pero no tengo ningún objeto
};
ListaMascotas::~ListaMascotas(){
    for (int i = 0; i < this->length ; ++i) {
        delete this->mascotas[i];
    }
    delete( this->mascotas );
};
Mascota* ListaMascotas::get(int posicion){
    return this->mascotas[posicion];
};
void ListaMascotas::add(Mascota* mascota){
    this->mascotas[this->length] = mascota;
    this->length++;
};
int ListaMascotas::getlength() {
    return this->length;
};
