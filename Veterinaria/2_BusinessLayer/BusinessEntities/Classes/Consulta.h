//
// Created by juanr on 11/3/2018.
//

#ifndef VETERINARIA_CONSULTA_H
#define VETERINARIA_CONSULTA_H


#include <string>
#include "../../../Cross-Cutting/DataTypes/Fecha.h"

class Consulta {
private:
    std::string motivo;
    Fecha fecha;
protected:
public:
    Consulta();

    Consulta(const std::string &motivo, const Fecha &fecha);

    virtual ~Consulta();

    const std::string &getMotivo() const;

    void setMotivo(const std::string &motivo);

    const Fecha &getFecha() const;

    void setFecha(const Fecha &fecha);
};


#endif //VETERINARIA_CONSULTA_H
