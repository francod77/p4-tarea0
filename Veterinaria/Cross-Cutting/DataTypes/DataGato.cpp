//
// Created by juanr on 11/3/2018.
//

#include "DataGato.h"

DataGato::DataGato() {}

DataGato::DataGato(const std::string &nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo)
        : DataMascota(nombre, genero, peso, racionDiaria), tipoPelo(tipoPelo) {}

DataGato::~DataGato() {

}

TipoPelo DataGato::getTipoPelo() const {
    return tipoPelo;
}

void DataGato::setTipoPelo(TipoPelo tipoPelo) {
    DataGato::tipoPelo = tipoPelo;
}
