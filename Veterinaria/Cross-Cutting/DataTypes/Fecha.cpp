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
    if(getAnio(this)<getAnio(fecha2))
        return true;
    if(getAnio(this)==getAnio(fecha2)){
        if(getMes(this)<getMes(fecha2)){
            return true;
        }
        if(getMes(this)==getMes(fecha2)){
            if(getDia(this)<getDia(fecha2))
                return true;
        }
    }
    return false;
}
