#ifndef VETERINARIA_VETERINARIAADMINISTRATION_H
#define VETERINARIA_VETERINARIAADMINISTRATION_H

#include "../BusinessEntities/Classes/Socio.h"
#include <string>
#include "../../Cross-Cutting/DataTypes/DataConsulta.h"
#include "../../Cross-Cutting/DataTypes/DataMascota.h"
#include "../../Cross-Cutting/Const.h"

class VeterinariaAdministration {
private:
    Socio **socios;
    int cantsocios;//cant de socios actual
public:
    VeterinariaAdministration();

    virtual ~VeterinariaAdministration();

    Socio *busqueda(std::string ci);

    void registrarSocio(std::string ci, std::string nombre, const DataMascota &dtMascota);

    void eliminar_socio(std::string ci);

    void agregarMascota(std::string ci,  DataMascota* dtmascota);

    void ingresarConsulta(std::string motivo, std::string ci);

    DataConsulta **verConsultasAntesDeFecha(const Fecha &Fecha, std::string ci, int &cantConsultas);

    DataMascota **obtenerMascotas(std::string ci, int &cantMascotas);
};


#endif //VETERINARIA_VETERINARIAADMINISTRATION_H
