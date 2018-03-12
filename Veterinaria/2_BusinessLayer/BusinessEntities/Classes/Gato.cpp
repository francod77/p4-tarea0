#include "Gato.h"

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
