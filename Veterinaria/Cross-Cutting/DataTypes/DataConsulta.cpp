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

void DataConsulta::print() {
    std::cout << "\t Fecha:  " ;
    int a,b,c;
    a = this->fechaConsulta.getDia();
    b=this->fechaConsulta.getMes();
    c=this->fechaConsulta.getAnio();
    std::cout <<  a ;
    std::cout <<"/"  ;
    std::cout <<b ;
    std::cout <<"/";
    std::cout <<c << std::endl;
    std::cout << "\t Motivo: ";
    std::cout << this->getMotivo() <<std::endl;
}

std::ostream& operator<< (const std::ostream& stream, DataConsulta &dataConsulta){
    dataConsulta.print();
}