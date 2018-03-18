//
// Created by juanr on 11/3/2018.
//

#include <stdexcept>
#include <typeinfo>
#include "Socio.h"
#include "../../../Cross-Cutting/Const.h"
#include "../../../Cross-Cutting/DataTypes/DataPerro.h"
#include "../../../Cross-Cutting/DataTypes/DataMascota.h"
#include "Perro.h"
#include "../../../Cross-Cutting/DataTypes/DataGato.h"
#include "Gato.h"


Socio::Socio() {
    this->listaMascotas = new ListaMascotas();
    this->listaConsultas = new ListaConsultas();
}

Socio::Socio(const std::string &ci, const std::string &nombre, const Fecha &fechaIngreso) : ci(ci), nombre(nombre),
                                                                                            fechaIngreso(
                                                                                                    fechaIngreso) {
    this->listaMascotas = new ListaMascotas();
    this->listaConsultas = new ListaConsultas();
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
        auto *nuevacons = new Consulta(motivo, fecha);
        this->listaConsultas->add(nuevacons);
    } else {
        throw std::invalid_argument("No puede agregar más consultas");
    }
}

void Socio::agregar_Mascota( const DataMascota &mascota) {
    if (this->listaMascotas->getlength() < MAX_MASCOTAS) {
        Mascota *nuevo;
       if(typeid(mascota) == typeid(DataPerro)){
            DataPerro dp = (DataPerro&)mascota;
            nuevo = new Perro(mascota.getNombre(), mascota.getGenero(), mascota.getPeso(),
                                         mascota.getRacionDiaria(),dp.getRaza(), dp.isVacunaCachorro() );
        }else{
            DataGato dg = (DataGato&)mascota;
            nuevo = new Gato(mascota.getNombre(), mascota.getGenero(), mascota.getPeso(),
                              mascota.getRacionDiaria(),dg.getTipoPelo());
        }

        this->listaMascotas->add(nuevo);
    } else {
        throw std::invalid_argument("No puede agregar más mascotas");
    }
}

DataConsulta **Socio::getConsultasAntesDeFecha(Fecha f, int maxConsultas) {
    auto **res = new DataConsulta *[maxConsultas];
    int j=0;
    for (int i = 0; i < this->listaConsultas->getlength() && j<maxConsultas; ++i) {
        if (this->listaConsultas->get(i)->getFecha() < f) {
            res[j] = this->listaConsultas->get(i)->getDataConsulta();
            j++;
        }
   };
    return res;
//    int cantConsultas = 0;
//    for (int i = 0; i < this->listaConsultas->getlength(); ++i) {
//        if (this->listaConsultas->get(i)->getFecha() < f) {
//            cantConsultas++;
//        }
//    };
//    if (cantConsultas > maxConsultas) {
//        cantConsultas = maxConsultas;
//    }
//    DataConsulta **res = new DataConsulta *[cantConsultas];
//    int j=0;
//    for (int i = 0; i < cantConsultas; ++i) {
//        if (this->listaConsultas->get(i)->getFecha() < f) {
//            res[j] = this->listaConsultas->get(i)->getDataConsulta();
//            j++;
//        }
//    };
//    return res;
}

DataMascota **Socio::getListaMascotas() {
    int cantMascotasSocio = this->listaMascotas->getlength();
    Mascota* m;
    auto **res = new DataMascota *[cantMascotasSocio];
    DataMascota* aux;
    for (int i = 0; i < cantMascotasSocio; ++i) {
        m=this->listaMascotas->get(i);
        if(typeid(m) == typeid(Perro&)) {
            aux=new DataPerro();
            aux->setNombre(m->getNombre());
            aux->setPeso(m->getPeso());
            aux->setGenero(m->getGenero());
            aux->setRacionDiaria(m->getRacionDiaria());
            ((DataPerro*)aux)->setRaza(((Perro*)m)->getRaza());
            ((DataPerro*)aux)->setVacunaCachorro(((Perro*)m)->isVacunaCachorro());
            res[i] = aux;
        } else {
            aux=new DataGato();
            aux->setNombre(m->getNombre());
            aux->setPeso(m->getPeso());
            aux->setGenero(m->getGenero());
            aux->setRacionDiaria(m->getRacionDiaria());
            ((DataGato*)aux)->setTipoPelo(((Gato*)m)->getTipoPelo());
            res[i] = aux;
        };
    };
    return res;
};

DataConsulta **Socio::getListaConsultas() {
    int cantConsultas = this->listaConsultas->getlength();
    auto **res = new DataConsulta *[cantConsultas];
    for (int i = 0; i < cantConsultas; ++i) {
        res[i] = this->listaConsultas->get(i)->getDataConsulta();
    };
    return res;
}

int Socio::getlargolistamascotas(){
    return this->listaMascotas->getlength();
};