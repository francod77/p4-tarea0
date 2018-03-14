//
// Created by juanr on 12/3/2018.
//

#include "ListaMascotas.h"
#include "Mascota.h"
#include "../../../Cross-Cutting/Const.h"

void ListaMascotas::ListaMascotas(int length){
    this->mascotas = new Mascota[Constantes.MAX_MASCOTAS];
    this->length = 0;//Reserve el tamaño en memoria pero no tengo ningún objeto
};

ListaMascotas::~ListaMascotas(){
    for (int i = 0; i < this->length ; ++i) {
        delete this->mascotas[i];
    }
    delete this->mascotas;
};
//esta como llego aca? no sirve y esta mal hecha
Mascota ListaMascotas::get(int num){
    return this->consultas[num];
};
int ListaMascotas::getlength() {
    return this->length;
};
void ListaMascotas::add(Mascota mascota){
    this->mascotas[this->length]=mascota;
    this->length++;
};
DataMascota* ListaMascotas::getmascota(int num){
    DataMascota* datos(mascotas[num]->getNombre(),mascotas[num]->getGenero(),mascotas[num]->getPeso(),mascotas[num]->getRacionDiaria());
    //creo el tipo de datos a partir de los datos en mascotas
    return datos;
};
