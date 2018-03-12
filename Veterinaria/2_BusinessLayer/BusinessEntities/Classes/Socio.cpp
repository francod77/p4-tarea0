//
// Created by juanr on 11/3/2018.
//

#include "Socio.h"

Socio::Socio() {}

Socio::~Socio() {

}

const std::string &Socio::getCi() const {
    return ci;
}

void Socio::setCi(const std::string &ci) {
    Socio::ci = ci;
}

const std::string &Socio::getNombre() const {
    return nombre;
}

void Socio::setNombre(const std::string &nombre) {
    Socio::nombre = nombre;
}

const Fecha &Socio::getFechaIngfreso() const {
    return fechaIngfreso;
}

void Socio::setFechaIngfreso(const Fecha &fechaIngfreso) {
    Socio::fechaIngfreso = fechaIngfreso;
}
