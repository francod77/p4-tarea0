#include <iostream>
#include "DataPerro.h"

DataPerro::DataPerro(): DataMascota() {}

DataPerro::DataPerro(std::string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza,
                     bool vacunaCachorro) : DataMascota(nombre, genero, peso, racionDiaria), raza(raza),
                                            vacunaCachorro(vacunaCachorro) {}

DataPerro::~DataPerro() {

}

RazaPerro DataPerro::getRaza() const {
    return raza;
}

void DataPerro::setRaza(RazaPerro raza) {
    DataPerro::raza = raza;
}

bool DataPerro::isVacunaCachorro() const {
    return vacunaCachorro;
}

void DataPerro::setVacunaCachorro(bool vacunaCachorro) {
    DataPerro::vacunaCachorro = vacunaCachorro;
}

bool DataPerro::getvacunaCachorro() {
    return vacunaCachorro;
}

void DataPerro::print(){
    if(this->vacunaCachorro){
        std::cout << "- Tiene vacuna del Cachorro: Si" << std::endl;
    }else{
        std::cout << "- Tiene vacuna del Cachorro: No" << std::endl;
    }

}