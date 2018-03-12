#include "Socio.h"
#include "../../../Cross-Cutting/Const.h"

Socio::Socio() {
    Const c;
}

Socio::Socio(const std::string &ci, const std::string &nombre, const Fecha &fechaIngfreso) : ci(ci), nombre(nombre),
                                                                                             fechaIngfreso(
                                                                                                     fechaIngfreso) {

}


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

void agregarConsulta(std::string motivo, Fecha fecha){

}

void agregarMascota(DataMascota mascota){

}