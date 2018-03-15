#include "Fecha.h"
Fecha::Fecha(){}

Fecha::Fecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

Fecha::~Fecha(){}

int Fecha::getDia() const {
    return dia;
}

void Fecha::setDia(int dia) {
    Fecha::dia = dia;
}

int Fecha::getMes() const {
    return mes;
}

void Fecha::setMes(int mes) {
    Fecha::mes = mes;
}

int Fecha::getAnio() const {
    return anio;
}

void Fecha::setAnio(int anio) {
    Fecha::anio = anio;
}

bool Fecha::operator<(Fecha fecha2){
    if(this->getAnio()<fecha2.getAnio())
        return true;
    if(this->getAnio()==fecha2.getAnio()){
        if(this->getMes()<fecha2.getMes()){
            return true;
        }
        if(this->getMes()==fecha2.getMes()){
            if(this->getDia()<fecha2.getDia()) {
                return true;
            }
        }
    }
    return false;
}
