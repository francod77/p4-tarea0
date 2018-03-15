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

Fecha Consulta::getFecha(){
    return fecha;
}

void Consulta::setFecha(Fecha fecha) {
    Consulta::fecha = fecha;
}

DataConsulta* Consulta::getDataConsulta(){
    return new DataConsulta(this->fecha, this->motivo);
}