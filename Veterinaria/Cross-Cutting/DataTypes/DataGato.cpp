#include <iostream>
#include "DataGato.h"

DataGato::DataGato(): DataMascota() {}

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

void DataGato::print() {
    std::string aux=this->getNombre();
    std::cout << " - Nombre: "<< aux << std::endl;

    if ( this->getGenero()==masculino)
        aux="masculino";
    else
        aux="femenino";
    std::cout << "- Género: "<< aux << std::endl;

    float a=this->getPeso();
    std::cout << "- Peso: " <<  a << " kg"<< std::endl;

    a=this->getRacionDiaria();
    std::cout << "- Ración Diaria: " << a <<std::endl;

    switch (this->tipoPelo) {
        case 0:
            std::cout << "- TipoPelo: corto " << std::endl;
            break;
        case 1:
            std::cout << "- TipoPelo: mediano " << std::endl;
            break;
        case 2: std::cout << "- TipoPelo: largo " << std::endl;
            break;
    }
}
