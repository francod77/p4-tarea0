#include "DataMascota.h"

DataMascota::DataMascota() {}

DataMascota::DataMascota(const std::string &nombre, Genero genero, float peso, float racionDiaria) : nombre(nombre),
                                                                                                     genero(genero),
                                                                                                     peso(peso),
                                                                                                     racionDiaria(
                                                                                                             racionDiaria) {}

DataMascota::~DataMascota() {

}

const std::string &DataMascota::getNombre() const {
    return nombre;
}

void DataMascota::setNombre(const std::string &nombre) {
    DataMascota::nombre = nombre;
}

Genero DataMascota::getGenero() const {
    return genero;
}

void DataMascota::setGenero(Genero genero) {
    DataMascota::genero = genero;
}

float DataMascota::getPeso() const {
    return peso;
}

void DataMascota::setPeso(float peso) {
    DataMascota::peso = peso;
}

float DataMascota::getRacionDiaria() const {
    return racionDiaria;
}

void DataMascota::setRacionDiaria(float racionDiaria) {
    DataMascota::racionDiaria = racionDiaria;
}
