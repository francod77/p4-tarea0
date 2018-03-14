#include <stdexcept>
#include "VeterinariaAdministration.h"


VeterinariaAdministration::VeterinariaAdministration() {
    this->socios = new Socio*[MAX_SOCIOS];
    this->cantsocios=0;
};

VeterinariaAdministration::~VeterinariaAdministration(){};

Socio* VeterinariaAdministration::busqueda(std::string ci) {
    int i = 0;
    while (i < this->cantsocios && ci.compare(this->socios[i]->getCi()) == 0){
        i++;
    }
    if(i < this->cantsocios){
        return this->socios[i];
    }else{
        throw std::invalid_argument("No existe un socio registrado con esa cédula");
    }
    return NULL;
};

void VeterinariaAdministration::registrarSocio(std::string ci, std::string nombre, const DataMascota& dtMascota){
    Fecha f;
    f.setAnio(2018);
    f.setMes(3);
    f.setDia(14);
    Socio* nuevo = new Socio(ci,nombre,f);
    nuevo->agregar_Mascota(dtMascota);//agregamos la primer mascota
    this->socios[this->cantsocios]=nuevo;
    this->cantsocios++;
}
void VeterinariaAdministration::eliminar_socio(std::string ci){
    int i = 0;
    while (i < this->cantsocios && ci.compare(this->socios[i]->getCi()) == 0){
        i++;
    }
    if(i < this->cantsocios){
        Socio *elsocio = this->socios[i];
        this->socios[i] = this->socios[this->cantsocios-1];
        this->socios[this->cantsocios-1] = NULL;
        this->cantsocios--;
        delete elsocio;
    }else{
        throw std::invalid_argument("No existe un socio registrado con esa cédula");
    }
};

void VeterinariaAdministration::agregarMascota(std::string ci, DataMascota dtmascota){
    Socio* cliente = busqueda(ci);
    if (cliente != nullptr){
        cliente->agregar_Mascota(dtmascota);
    }else{
        throw std::invalid_argument("No existe un socio registrado con esa cédula");
    }
};
void VeterinariaAdministration::ingresarConsulta(std::string motivo,std::string ci){
    Socio *elsocio = busqueda(ci);
    Fecha f;
    f.setAnio(2018);
    f.setMes(3);
    f.setDia(14);
    elsocio->agregar_Consulta(motivo, f);
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
    Socio* cliente= busqueda(ci);
    //falta implementar la excepcion
    if (cliente!= nullptr) {
        return cliente->getlistamascotas(cantMascotas);
    }else{
        throw std::invalid_argument("No existe un socio registrado con esa cédula");
    }
};
