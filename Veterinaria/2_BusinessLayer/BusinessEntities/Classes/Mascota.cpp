#include "Mascota.h"

Mascota::Mascota() {}

Mascota::Mascota(const std::string &nombre, Genero genero, float peso, float racionDiaria) : nombre(nombre),
                                                                                             genero(genero), peso(peso),
                                                                                             racionDiaria(
                                                                                                     racionDiaria) {}
Mascota::~Mascota() {

}

const std::string &Mascota::getNombre() const {
    return nombre;
}

void Mascota::setNombre(const std::string &nombre) {
    Mascota::nombre = nombre;
}

Genero Mascota::getGenero() const {
    return genero;
}

void Mascota::setGenero(Genero genero) {
    Mascota::genero = genero;
}

float Mascota::getPeso() const {
    return peso;
}

void Mascota::setPeso(float peso) {
    Mascota::peso = peso;
}

float Mascota::getRacionDiaria() const {
    return racionDiaria;
}

void Mascota::setRacionDiaria(float racionDiaria) {
    Mascota::racionDiaria = racionDiaria;
}
