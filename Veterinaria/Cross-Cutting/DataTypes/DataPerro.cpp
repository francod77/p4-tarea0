#include "DataPerro.h"

DataPerro::DataPerro() {}

DataPerro::DataPerro(const std::string &nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza,
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
