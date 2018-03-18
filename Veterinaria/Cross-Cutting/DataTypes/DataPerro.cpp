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

void DataPerro::print() const{
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
    switch ((int)this->raza){
        case 0:
            salida= "Labrador";
            break;
        case 1:
            salida= "Ovejero";
            break;
        case 2:
            salida= "Bulldog";
            break;
        case 3:
            salida= "Pitbull";
            break;
        case 4:
            salida= "Collie";
            break;
        case 5:
            salida= "Pekines";
            break;
        case 6:
            salida= "Otro";
            break;
    };
    std::cout << "\t\t- Raza: " << salida << std::endl;

    if(this->vacunaCachorro){
        salida = "Si";
    } else{
        salida = "No";
    }
    std::cout << "\t\t- Tiene Vacuna Cachorro: " << salida << std::endl;

}