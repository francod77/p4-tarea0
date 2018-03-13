#ifndef VETERINARIA_VETERINARIAADMINISTRATION_H
#define VETERINARIA_VETERINARIAADMINISTRATION_H

#include "../BusinessEntities/classes/Socio.h"
#include <string>
#include "../../Cross-Cutting/DataTypes/DataConsulta.h"
#include "../../Cross-Cutting/DataTypes/DataMascota.h"
#include "../../Cross-Cutting/Const.h"
#include "VeterinariaAdministration.cpp"

class VeterinariaAdministration {
private:
    Socio socios[1000];//aca va MAX_SOCIOS
    int cantsocios;//cant de socios actual
public:
    VeterinariaAdministration();
    virtual ~VeterinariaAdministration();
    Socio busqueda(std::string ci,int cant_socios);
    void registrarSocio(std::string ci, std::string nombre, const DataMascota& dtMascota);
    void eliminar_socio(std::string ci);
    void agregarMascota(std::string ci, DataMascota dtmascota);
    void ingresarConsulta(std::string motivo,std::string ci);
    void setcantsocios(bool agrega);//agrega uno o saca uno a cantsocios
    int getcantsocios();
    DataConsulta** verConsultasAntesDeFecha(const Fecha& Fecha, std::string ci, int& cantConsultas);
    DataMascota** obtenerMascotas(std::string ci, int& cantMascotas);
};


#endif //VETERINARIA_VETERINARIAADMINISTRATION_H
