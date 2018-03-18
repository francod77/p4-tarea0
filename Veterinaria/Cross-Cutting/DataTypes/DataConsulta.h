#ifndef VETERINARIA_DATACONSULTA_H
#define VETERINARIA_DATACONSULTA_H


#include "Fecha.h"
#include <string>
#include <iostream>

class DataConsulta {
private:
    Fecha fechaConsulta;
    std::string motivo;
public:
    DataConsulta();

    DataConsulta(const Fecha &fechaConsulta, const std::string &motivo);

    virtual ~DataConsulta();

    const Fecha &getFechaConsulta() const;

    void setFechaConsulta(const Fecha &fechaConsulta);

    const std::string &getMotivo() const;

    void setMotivo(const std::string &motivo);

    void print();
};

std::ostream &operator<<(const std::ostream &stream, DataConsulta &dataMascota);
#endif //VETERINARIA_DATACONSULTA_H
