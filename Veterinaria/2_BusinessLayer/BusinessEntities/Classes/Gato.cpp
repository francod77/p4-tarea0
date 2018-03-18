#include "Gato.h"
#include "../../../Cross-Cutting/DataTypes/DataGato.h"

Gato::Gato() {}

Gato::Gato(const std::string &nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo) : Mascota(
        nombre, genero, peso, racionDiaria), tipoPelo(tipoPelo) {}

Gato::~Gato() {

}

TipoPelo Gato::getTipoPelo() const {
    return tipoPelo;
}

void Gato::setTipoPelo(TipoPelo tipoPelo) {
    Gato::tipoPelo = tipoPelo;
}


DataMascota *Gato::getDataMascota() {
    return new DataGato(this->getNombre(), this->getGenero(), this->getPeso(), this->getRacionDiaria(),
                        this->getTipoPelo());
}
