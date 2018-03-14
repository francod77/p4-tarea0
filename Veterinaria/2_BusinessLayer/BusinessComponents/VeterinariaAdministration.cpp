#include "VeterinariaAdministration.h"


VeterinariaAdministration::VeterinariaAdministration() {
    //this->socios= new Socio[MAX_SOCIOS]; ya se declara en .h
    this->cantsocios=0;
};

VeterinariaAdministration::~VeterinariaAdministration(){};

Socio* VeterinariaAdministration::busqueda(std::string ci) {
    try {
        int i = 0;
        bool encontre = false;
        while ((!encontre && i <= Constantes.MAX_SOCIO) && i <= this->cantsocios) {
            encontre = (ci == this->socios[i]->getCi());
            i++;
        }
        if (i < cant)
            return this->socios[i - 1];
        else
            throw std::invalid_argument("No existe un socio registrado con esa cédula");
    }
};

void VeterinariaAdministration::registrarSocio(std::string ci, std::string nombre, const DataMascota& dtMascota){
    Socio* nuevo(ci,nombre,fecha);
    nuevo->agregar_Mascota(dtMascota);//agregamos la primer mascota
    this->socios[this->cantsocios]=nuevo;
    this->cantsocios++;
}
void VeterinariaAdministration::eliminar_socio(std::string ci){
    try {
        int pos=5;//tiene que ser !=0
        Socio *elsocio = busqueda(ci,pos);
        elsocio->~Socio();//borramos elsocio
        if(pos<= (this->cantsocios-1) ) {
            elsocio = this->socios[this->cantsocios - 1];//elsocio ahora es el ultimo
            this->socios[pos] = elsocio;
            //delete this->socios[this->cantsocios - 1];//no es necesario, simplemente sobreescribimos en la proxima?
        }
        this->cantsocios--;
    }
    catch(const std::invalid_argument &error){
        //haces algo
    }
};

void VeterinariaAdministration::agregarMascota(std::string ci, DataMascota dtmascota){
    Socio* cliente = busqueda(ci);
    if (cliente != nullptr){
        cliente->agregar_Mascota(dtmascota);
    }else
        //excepcion std::invalid argument
};
void VeterinariaAdministration::ingresarConsulta(std::string motivo,std::string ci){
    try{
        Socio *elsocio = busqueda(ci);
        elsocio->agregar_Consulta(motivo, fecha);
    }
    catch (const std::invalid_argument &error){
        //haces algo
    }
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
    if (cliente!= nullptr)
        return cliente->getlistamascotas(cantMascotas);
    else //excepcion
};
