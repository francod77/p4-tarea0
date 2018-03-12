//
// Created by juanr on 11/3/2018.
//

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
