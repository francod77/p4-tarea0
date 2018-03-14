//
// Created by juanr on 11/3/2018.
//

#include "Socio.h"
#include "../../../Cross-Cutting/Const.h"
#include "../../../Cross-Cutting/DataTypes/DataMascota.h"
#include "ListaConsultas.h"
#include "ListaMascotas.h"
#include "Mascota.h"

Socio::Socio() {
    this->listaMascotas = new ListaMascotas(10);
    this->listaConsultas = new ListaConsultas(1000);
}

Socio::Socio(const std::string &ci, const std::string &nombre, const Fecha &fechaIngreso) : ci(ci), nombre(nombre),
                                                                                             fechaIngreso(
                                                                                                     fechaIngreso) {
    this->listaMascotas = new ListaMascotas(10);
    this->listaConsultas = new ListaConsultas(1000);
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

const Fecha &Socio::getFechaIngreso() const {
    return fechaIngreso;
}

void Socio::setFechaIngreso(const Fecha &fechaIngreso) {
    Socio::fechaIngreso = fechaIngreso;
}

 void Socio::agregar_Consulta(std::string motivo, Fecha fecha){
    Consulta* nuevacons=new Consulta(motivo,fecha);
    Socio->listaConsultas.add(nuevacons);
}

void Socio::agregar_Mascota(DataMascota mascota){
    if(this->listaMascotas->getlength()<MAX_MASCOTAS) {
        Mascota *nuevo = new Mascota(mascota.getNombre(), mascota.getGenero(), mascota.getPeso(),
                                     mascota.getRacionDiaria());
        Socio->listaMascotas.add(nuevo);
    } else //exception ???
}

DataMascota** Socio::getlistamascotas(int cant){
    DataMascota** res;//arreglo de punteros a datamascota de largo cant
    //hay que inicializar res
    for (int i = 0; i <cant ; ++i) {
        res[i]=this->listaMascotas->getmascota(i);
    };
    return res;
};