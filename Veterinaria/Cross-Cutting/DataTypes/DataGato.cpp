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

void DataGato::print() const {
    std::cout << "\t\t- Nombre: "<< this->getNombre() << std::endl;
    std::string salida = "";
    switch ((int)this->getGenero()){
        case 0:
            salida= "Masculino";
            break;
        case 1:
            salida= "Femenino";
            break;
    };
    std::cout << "\t\t- Género: "<< salida << std::endl;
    std::cout << "\t\t- Peso: " <<  this->getPeso() << " kg"<< std::endl;
    std::cout << "\t\t- Ración Diaria: " << this->getRacionDiaria() <<std::endl;
    switch ((int)this->getTipoPelo()){
        case 0:
            salida= "Corto";
            break;
        case 1:
            salida= "Mediano";
            break;
        case 2:
            salida= "Largo";
            break;
    };
    std::cout << "\t\t- TipoPelo: " << salida << std::endl;
}
