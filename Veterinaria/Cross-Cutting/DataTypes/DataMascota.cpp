#include <iostream>
#include "DataMascota.h"
#include "DataPerro.h"
#include "DataGato.h"
#include "../Const.h"

DataMascota::DataMascota() {}

DataMascota::DataMascota(std::string nombre, Genero genero, float peso, float racionDiaria) : nombre(nombre), genero(genero), peso(peso), racionDiaria(racionDiaria) {}

DataMascota::~DataMascota() {

}

 const std::string &DataMascota::getNombre()  const{
    return nombre;
}

 void DataMascota::setNombre(const std::string &nombre) {
    DataMascota::nombre = nombre;
}

Genero DataMascota::getGenero() const {
    return genero;
}

 void DataMascota::setGenero(Genero genero) {
    //DataMascota::genero = genero;
     this->genero=genero;
}

float DataMascota::getPeso() const  {
    return peso;
}

 void DataMascota::setPeso(float peso) {
    DataMascota::peso = peso;
}

float DataMascota::getRacionDiaria() const  {
    return racionDiaria;
}

 void DataMascota::setRacionDiaria(float racionDiaria) {
    DataMascota::racionDiaria = racionDiaria;
}

 void DataMascota::print(){
     std::string aux=this->nombre;
    std::cout << "- Nombre: "<< aux << std::endl;

     if ( this->genero==masculino) aux="masculino";
     else aux="femenino";
    std::cout << "- Género: "<< aux << std::endl;
     float a=this->peso;
     std::cout << "- Peso: " <<  a << " kg"<< std::endl;
     a=this->racionDiaria;
    std::cout << "- Ración Diaria: " << a <<std::endl;

     if(typeid(this)== typeid(DataPerro&)) {//si es perro
         auto *Dtaux = dynamic_cast<DataPerro *> (this);
         aux = std::to_string(Dtaux->getRaza());
         std::cout << "- Raza: " << aux << std::endl;

         aux= Dtaux->getvacunaCachorro();
         std::cout << "- Tiene Vacuna Cachorro: " << aux << std::endl;
     }else{//es gato
         auto * Dtaux=dynamic_cast<DataGato *> (this);
         aux = std::to_string(Dtaux->getTipoPelo());
         std::cout << "- TipoPelo: " << aux << std::endl;
     }
}

std::ostream& operator<< (std::ostream& stream, DataMascota &dataMascota){
    dataMascota.print();
}

