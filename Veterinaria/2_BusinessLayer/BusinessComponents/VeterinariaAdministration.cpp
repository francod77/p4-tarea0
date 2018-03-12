#include "VeterinariaAdministration.h"

Socio busqueda(Socio *arreglo,std::string ci,int cant){
    int i=0;
    bool encontre=false;
    while ((!encontre && i<=Constantes.MAX_SOCIO) && i<=cant) {
        encontre=(ci==arreglo[i].getCi());
        i++;
    }
    if(i<cant)
        return arreglo[i-1];
    else
        return NULL;
};

void VeterinariaAdministration::registrarSocio(std::string ci, std::string nombre, const DataMascota& dtMascota){
    Socio nuevo=new Socio(ci,nombre,fecha);
    agregar_mascota(ci,dtMascota);//agregamos la primer mascota
    VeterinariaAdministration.socios[VeterinariaAdministration.cantsocios]=nuevo;
    VeterinariaAdministration.cantsocios++;
};
void eliminar_socio(std::string ci);
void agregarMascota(std::string ci, DataMascota dtmascota);
void ingresarConsultas(std::string motivo,std::string ci);
DataConsulta** verConsultasAntesDeFecha(const Fecha& Fecha, std::string ci, int& cantConsultas);
DataMascota** obtenerMascotas(std::string ci, int& cantMascotas){};
