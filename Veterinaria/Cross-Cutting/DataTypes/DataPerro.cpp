#include <iostream>
#include "DataPerro.h"

DataPerro::DataPerro(): DataMascota() {}

DataPerro::DataPerro(std::string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza,
                     bool vacunaCachorro) : DataMascota(nombre, genero, peso, racionDiaria), raza(raza),
                                            vacunaCachorro(vacunaCachorro) {}

DataPerro::~DataPerro() = default;

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
    std::string aux=this->getNombre();
    std::cout << "- Nombre: "<< aux << std::endl;

    if ( this->getGenero()==masculino) aux="masculino";
    else aux="femenino";
    std::cout << "- Género: "<< aux << std::endl;

    float a=this->getPeso();
    std::cout << "- Peso: " <<  a << " kg"<< std::endl;

    a=this->getRacionDiaria();
    std::cout << "- Ración Diaria: " << a <<std::endl;

    aux = std::to_string(this->raza);
    std::cout << "- Raza: " << aux << std::endl;

    if (this->vacunaCachorro)
        std::cout << "- Tiene Vacuna Cachorro: si"  << std::endl;
    else std::cout << "- Tiene Vacuna Cachorro: no"  << std::endl;

}