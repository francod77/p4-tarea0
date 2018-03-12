#include "Consulta.h"

Consulta::Consulta() {}

Consulta::Consulta(const std::string &motivo, const Fecha &fecha) : motivo(motivo), fecha(fecha) {}

Consulta::~Consulta() {

}

const std::string &Consulta::getMotivo() const {
    return motivo;
}

void Consulta::setMotivo(const std::string &motivo) {
    Consulta::motivo = motivo;
}

const Fecha &Consulta::getFecha() const {
    return fecha;
}

void Consulta::setFecha(const Fecha &fecha) {
    Consulta::fecha = fecha;
}
