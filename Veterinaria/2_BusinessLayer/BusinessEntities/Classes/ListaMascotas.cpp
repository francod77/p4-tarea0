//
// Created by juanr on 12/3/2018.
//

#include "ListaMascotas.h"
#include "Mascota.h"
#include "../../../Cross-Cutting/Const.h"

ListaMascotas::ListaMascotas(int length){
    this->mascotas = new Mascota*[length];
    this->length = 0;//Reserve el tamaño en memoria pero no tengo ningún objeto
};

ListaMascotas::~ListaMascotas(){
    for (int i = 0; i < this->length ; ++i) {
        delete this->mascotas[i];
    }
    delete this->mascotas;
};

Mascota* ListaMascotas::get(int num){
    return this->mascotas[num];
};
int ListaMascotas::getlength() {
    return this->length;
};
void ListaMascotas::add(Mascota* mascota){
    this->mascotas[this->length] = mascota;
    this->length++;
};
DataMascota* ListaMascotas::getmascota(int num){
    Genero genero = this->mascotas[num]->getGenero();
    DataMascota* datos = new DataMascota(this->mascotas[num]->getNombre(),genero,this->mascotas[num]->getPeso(),this->mascotas[num]->getRacionDiaria());
    //creo el tipo de datos a partir de los datos en mascotas
    return datos;
};
