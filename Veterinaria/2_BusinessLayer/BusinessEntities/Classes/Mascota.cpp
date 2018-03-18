#include "Mascota.h"
#include "Perro.h"
#include "Gato.h"
#include "../../../Cross-Cutting/DataTypes/DataPerro.h"
#include "../../../Cross-Cutting/DataTypes/DataGato.h"

Mascota::Mascota() {}

Mascota::Mascota(const std::string &nombre, Genero genero, float peso, float racionDiaria) : nombre(nombre),
                                                                                             genero(genero), peso(peso),
                                                                                             racionDiaria(
                                                                                                     racionDiaria) {}

Mascota::~Mascota() {
}

const std::string &Mascota::getNombre() const {
    return nombre;
}

void Mascota::setNombre(const std::string &nombre) {
    Mascota::nombre = nombre;
}

Genero Mascota::getGenero() const {
    return genero;
}

void Mascota::setGenero(Genero genero) {
    Mascota::genero = genero;
}

float Mascota::getPeso() const {
    return peso;
}

void Mascota::setPeso(float peso) {
    Mascota::peso = peso;
}

float Mascota::getRacionDiaria() const {
    return racionDiaria;
}

DataMascota* Mascota::getDataMascota(){
    if (typeid(this)==typeid(Perro)){
        Perro *aux= dynamic_cast<Perro*>(this);
         DataPerro* res= new DataPerro(this->getNombre(),this->getGenero(),this->getPeso(),this->getRacionDiaria(),aux->getRaza(),aux->isVacunaCachorro());
        return res;
    }else{
        Gato *aux= dynamic_cast<Gato*>( this);
        DataGato* res= new DataGato(this->getNombre(),this->getGenero(),this->getPeso(),this->getRacionDiaria(),aux->getTipoPelo());
        return res;
    }
};

//hay que ver si aca nos pasan la racion diaria o el peso
void Mascota::setRacionDiaria(float racionDiaria) {
    Mascota::racionDiaria = racionDiaria;
}
