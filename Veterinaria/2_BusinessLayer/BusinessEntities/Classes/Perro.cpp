//
// Created by juanr on 11/3/2018.
//

#include "Perro.h"

Perro::Perro() {}

Perro::Perro(const std::string &nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza,
             bool vacunaCachorro) : Mascota(nombre, genero, peso, racionDiaria), raza(raza),
                                    vacunaCachorro(vacunaCachorro) {}

Perro::~Perro() {

}

RazaPerro Perro::getRaza() const {
    return raza;
}

void Perro::setRaza(RazaPerro raza) {
    Perro::raza = raza;
}

bool Perro::isVacunaCachorro() const {
    return vacunaCachorro;
}

void Perro::setVacunaCachorro(bool vacunaCachorro) {
    Perro::vacunaCachorro = vacunaCachorro;
}
