#include "VeterinariaAdministration.h"

VeterinariaAdministration::VeterinariaAdministration() {
    //this->socios= new Socio[MAX_SOCIOS]; ya se declara en .h
    this->cantsocios=0;
};

VeterinariaAdministration::~VeterinariaAdministration(){};

Socio VeterinariaAdministration::busqueda(std::string ci,int cant){
    int i=0;
    bool encontre=false;
    while ((!encontre && i<=Constantes.MAX_SOCIO) && i<=cant) {
        encontre=(ci==this->socios[i].getCi());
        i++;
    }
    if(i<cant)
        return this->socios[i-1];
    else
        return nullptr;
};

void VeterinariaAdministration::registrarSocio(std::string ci, std::string nombre, const DataMascota& dtMascota){
    Socio nuevo=new Socio(ci,nombre,fecha);
    nuevo.agregar_Mascota(dtMascota);//agregamos la primer mascota
    this->socios[this->cantsocios]=nuevo;
    this->cantsocios++;
}
void VeterinariaAdministration::eliminar_socio(std::string ci){

};

void VeterinariaAdministration::agregarMascota(std::string ci, DataMascota dtmascota){
    Socio cliente = busqueda(ci,this->cantsocios);
    if (cliente != nullptr){
        cliente->agregar_Mascota(dtmascota);
    }else
        //excepcion std::invalid argument
};
void VeterinariaAdministration::ingresarConsulta(std::string motivo,std::string ci){

};
int VeterinariaAdministration::getcantsocios(){
    return this->cantsocios;
};

void VeterinariaAdministration::setcantsocios(bool agrega){
    if(agrega)  this->cantsocios++;
    else  this->cantsocios--;
};

DataConsulta** VeterinariaAdministration::verConsultasAntesDeFecha(const Fecha& Fecha, std::string ci, int& cantConsultas){

};
DataMascota** VeterinariaAdministration::obtenerMascotas(std::string ci, int& cantMascotas){
   
};
