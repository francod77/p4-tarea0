//
// Created by juanr on 11/3/2018.
//

#include <stdexcept>
#include "Socio.h"
#include "../../../Cross-Cutting/Const.h"

Socio::Socio() {
    this->listaMascotas = new ListaMascotas(MAX_MASCOTAS);
    this->listaConsultas = new ListaConsultas(MAX_CONSULTAS);
}

Socio::Socio(const std::string &ci, const std::string &nombre, const Fecha &fechaIngreso) : ci(ci), nombre(nombre),
                                                                                            fechaIngreso(
                                                                                                    fechaIngreso) {
    this->listaMascotas = new ListaMascotas(MAX_MASCOTAS);
    this->listaConsultas = new ListaConsultas(MAX_CONSULTAS);
}


Socio::~Socio() {
    delete this->listaConsultas;
    delete this->listaMascotas;
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

void Socio::agregar_Consulta(std::string motivo, Fecha fecha) {
    if (this->listaConsultas->getlength() < MAX_CONSULTAS) {
        Consulta *nuevacons = new Consulta(motivo, fecha);
        this->listaConsultas->add(nuevacons);
    } else {
        throw std::invalid_argument("No puede agregar más consultas");
    }
}

void Socio::agregar_Mascota(DataMascota mascota) {
    if (this->listaMascotas->getlength() < MAX_MASCOTAS) {
        Mascota *nuevo = new Mascota(mascota.getNombre(), mascota.getGenero(), mascota.getPeso(),
                                     mascota.getRacionDiaria());
        this->listaMascotas->add(nuevo);
    } else {
        throw std::invalid_argument("No puede agregar más mascotas");
    }
}

DataConsulta** Socio::getConsultasAntesDeFecha(Fecha f) {
    int cant = 0;
    DataConsulta **res = new DataConsulta*[cant];
    for (int i = 0; i < cant; ++i) {
        //esta comparacion se puede hacer??
        if (this->listaConsultas->get(i)->getFecha() < f) {
            res[cant] = this->listaConsultas->get(i)->getDataConsulta();
            cant++;
        }
    };
    return res;
}

DataMascota **Socio::getListaMascotas() {
    int cantMascotasSocio = this->listaMascotas->getlength();
    DataMascota **res = new DataMascota*[cantMascotasSocio];
    for (int i = 0; i < cantMascotasSocio; ++i) {
        res[i] = this->listaMascotas->get(i)->getDataMascota();
    };
    return res;
};

DataConsulta **Socio::getListaConsultas() {
    int cantConsultas = this->listaConsultas->getlength();
    DataConsulta **res = new DataConsulta*[cantConsultas];
    for (int i = 0; i < cantConsultas; ++i) {
        res[i] = this->listaConsultas->get(i)->getDataConsulta();
    };
    return res;
}
