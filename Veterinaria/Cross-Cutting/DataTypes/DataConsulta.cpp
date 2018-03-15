#include "DataConsulta.h"

DataConsulta::DataConsulta() {}

DataConsulta::DataConsulta(const Fecha &fechaConsulta, const std::string &motivo) : fechaConsulta(fechaConsulta),
                                                                                    motivo(motivo) {}

DataConsulta::~DataConsulta() {

}

const Fecha &DataConsulta::getFechaConsulta() const {
    return fechaConsulta;
}

void DataConsulta::setFechaConsulta(const Fecha &fechaConsulta) {
    DataConsulta::fechaConsulta = fechaConsulta;
}

const std::string &DataConsulta::getMotivo() const {
    return motivo;
}

void DataConsulta::setMotivo(const std::string &motivo) {
    DataConsulta::motivo = motivo;
}

void DataConsulta::imprimir_data() {
    std::cout << "\t fecha: /n ";
    std::cout << this->fechaConsulta.getDia() + "/";
    std::cout << this->fechaConsulta.getMes() + "/";
    std::cout << this->fechaConsulta.getAnio() + "/n" ;
    std::cout << "\t motivo: /n ";
    std::cout << this->getMotivo() + "/n";
}
