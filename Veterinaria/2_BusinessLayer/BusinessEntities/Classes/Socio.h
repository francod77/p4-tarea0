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

class Socio {
private:
    std::string ci;
    std::string nombre;
    Fecha fechaIngfreso;
    ListaConsultas* listaConsultas;
    ListaMascotas* listaMascotas;
public:
    Socio();

    Socio(const std::string &ci, const std::string &nombre, const Fecha &fechaIngfreso);

    virtual ~Socio();

    const std::string &getCi() const;

    void setCi(const std::string &ci);

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    const Fecha &getFechaIngfreso() const;

    void setFechaIngfreso(const Fecha &fechaIngfreso);

    void agregarConsulta(std::string motivo, Fecha fecha);

    void agregarMascota(DataMascota mascota);
    /*devuelve array de punteros datamascota sin comparrtir memoria!! es para usarse en obtener mascotas*/
    DataMascota** getlistamascotas(int cant);
};


#endif //VETERINARIA_SOCIO_H
