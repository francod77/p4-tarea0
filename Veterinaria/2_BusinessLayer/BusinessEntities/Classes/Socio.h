//
// Created by juanr on 11/3/2018.
//

#ifndef VETERINARIA_SOCIO_H
#define VETERINARIA_SOCIO_H


#include <string>
#include "../../../Cross-Cutting/DataTypes/Fecha.h"
#include "Consulta.h"
#include "Mascota.h"
#include "ListaConsultas.h"
#include "ListaMascotas.h"
#include "../../../Cross-Cutting/DataTypes/DataMascota.h"
#include "../../../Cross-Cutting/DataTypes/DataConsulta.h"

class Socio {
private:
    std::string ci;
    std::string nombre;
    Fecha fechaIngreso;
    ListaConsultas *listaConsultas;
    ListaMascotas *listaMascotas;
public:
    Socio();

    Socio(const std::string &ci, const std::string &nombre, const Fecha &fechaIngreso);

    virtual ~Socio();

    const std::string &getCi() const;

    void setCi(const std::string &ci);

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    const Fecha &getFechaIngreso() const;

    void setFechaIngreso(const Fecha &fechaIngreso);

    void agregar_Consulta(std::string motivo, Fecha fecha);

    void agregar_Mascota(const DataMascota &mascota);

    DataConsulta **getConsultasAntesDeFecha(Fecha f, int maxConsultas);

    /*devuelve array de punteros datamascota sin comparrtir memoria!! es para usarse en obtener mascotas*/
    DataMascota **getListaMascotas();

    DataConsulta **getListaConsultas();

    int getlargolistamascotas();
};


#endif //VETERINARIA_SOCIO_H
