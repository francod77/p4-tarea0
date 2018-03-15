#ifndef VETERINARIA_CONSULTA_H
#define VETERINARIA_CONSULTA_H


#include <string>
#include "../../../Cross-Cutting/DataTypes/Fecha.h"
#include "../../../Cross-Cutting/DataTypes/DataConsulta.h"

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

    Fecha getFecha();

    void setFecha(Fecha fecha);

    DataConsulta* getDataConsulta();
};


#endif //VETERINARIA_CONSULTA_H
