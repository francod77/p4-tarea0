#include "DataGato.h"

DataGato::DataGato() {}

DataGato::DataGato(std::string nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo)
        : DataMascota(nombre, genero, peso, racionDiaria), tipoPelo(tipoPelo) {}

DataGato::~DataGato() {

}

TipoPelo DataGato::getTipoPelo() const {
    return tipoPelo;
}

void DataGato::setTipoPelo(TipoPelo tipoPelo) {
    DataGato::tipoPelo = tipoPelo;
}
