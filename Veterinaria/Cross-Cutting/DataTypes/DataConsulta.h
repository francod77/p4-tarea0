//
// Created by juanr on 11/3/2018.
//

#ifndef VETERINARIA_DATACONSULTA_H
#define VETERINARIA_DATACONSULTA_H


#include "Fecha.h"
#include <string>

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
};


#endif //VETERINARIA_DATACONSULTA_H
