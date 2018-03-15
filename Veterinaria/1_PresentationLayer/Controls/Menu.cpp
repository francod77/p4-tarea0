#include <string>
#include <iostream>
#include <regex>
#include "Menu.h"
#include "../../Cross-Cutting/DataTypes/DataMascota.h"
#include "../../Cross-Cutting/DataTypes/DataGato.h"
#include "../../Cross-Cutting/DataTypes/DataPerro.h"
#include "../../Cross-Cutting/DataTypes/DataConsulta.h"

Menu::Menu(){

}
Menu::~Menu(){

}

void Menu::showGeneralMenu(){
    std::string menu = "Menú Principal\n\n";
    menu += "1) Registrar socio\n";
    menu += "2) Agregar mascota\n";
    menu += "3) Ingresar consulta\n";
    menu += "4) Ver Consulta antes de fecha\n";
    menu += "5) Eliminar socio\n";
    menu += "6) Obtener Mascotas\n";
    menu += "0) Salir\n\n";
    menu += "Opción:";
    std::cout << menu << std::endl;
}

int Menu::getMenuOption(){
    int option = -1;
    std::cin >> option;
    return option;
}

void Menu::leerOpcionRegistrarSocio(std::string &ci,std::string &nombre, DataMascota* &dataMascota){

    bool datoValido;
    bool mascotaPerro;
    std::string dato;
    std::smatch match;

    std::cout << "Registrar socio:" << std::endl;

    //Lectura del documento del socio
    std::cout << "\tIngrese el número de documento del socio: ";
    std::cin >> ci;

    //Lectura del nombre del socio
    std::cout << "\tIngrese el nombre del socio: ";
    std::cin >> nombre;

    //Lectura del tipo de mascota del socio
    datoValido = false;
    while (!datoValido){
        std::cout << "\tIndique que tipo de mascota va a registrar (gato o perro): ";
        std::cin >> dato;
        std::regex  r("\\s*(perro|gato)\\s*");
        if(regex_match(dato,match,r)){
            std::regex  r{R"(\s*gato\s*)"};
            if(regex_match(dato,match,r)){
                dataMascota = new DataGato();
                ((DataGato*)dataMascota)->setTipoPelo(largo);
                mascotaPerro = false;
            }else{
                dataMascota = new DataPerro();
                ((DataPerro*)dataMascota)->setRaza(labrador);
                mascotaPerro = true;
            }
            datoValido = true;
        }else{
            std::cout << "\tDato Incorrecto!!!"<< std::endl;
        }
    }

    //Lectura del nombre de la mascota
    std::cout << "\tIngrese el nombre de la mascota del socio (masculino o femenino): ";//#### no va la opcion M o F
    std::cin >> dato;
    dataMascota->setNombre(dato);

    //Lectura del genero de la mascota
    datoValido = false;
    while (!datoValido){
        std::cout << "\tIndique el genero de la mascota: ";
        std::cin >> dato;
        std::regex  r("\\s*(masculino|femenino)\\s*");
        if(regex_match(dato,match,r)){
            std::regex  r{R"(\s*masculino\s*)"};
            if(regex_match(dato,match,r)){
                dataMascota->setGenero(masculino);
            }else{
                dataMascota->setGenero(femenino);
            }
            datoValido = true;
        }else{
            std::cout << "\tDato Incorrecto!!!"<< std::endl;
        }
    }
}

void Menu::leer_consulta_nueva(std::string &motivo, std::string &ci) {
    std::cout << "Ingresar Consulta:" << std::endl;

    //Lectura del documento del socio
    std::cout << "\tIngrese el número de documento del socio: ";
    std::cin >> ci;
    //Lectura del motivo de consulta
    std::cout << "\tIngrese el motivo de la consulta: ";
    std::cin >> motivo;

};
void Menu::leer_verantesdefecha(Fecha & fecha, std::string & ci, int & cantconsultas) {
    int dia,mes,anio;
    std::cout << "Ver Consultas Antes de Fecha:" << std::endl;
    //Lectura del documento del socio
    std::cout << "\tIngrese el número de documento del socio: ";
    std::cin >> ci;

    //Lectura de la fecha limite
    std::cout << "\tIngrese el dia de la fecha limite: ";
    std::cin >> dia;
    std::cout << "\tIngrese el mes de la fecha limite: ";
    std::cin >> mes;
    std::cout << "\tIngrese el año de la fecha limite: ";
    std::cin >> anio;
    fecha.setDia(dia);
    fecha.setMes(mes);
    fecha.setAnio(anio);

    std::cout << "\tIngrese la cantidad de consultas maxima: ";
    std::cin >> cantconsultas;
}

void Menu::imprimir_dtconsulta(DataConsulta **dtcons,int cantconsultas) {
    for (int i = 0; i < cantconsultas ;++i) {
        dtcons[i]->imprimir_data();
    }
}

void Menu::leer_obtenermascotas(std::string &ci, int &cantmascotas) {
    std::cout << "Obtener Mascotas:" << std::endl;

    //Lectura del documento del socio
    std::cout << "\tIngrese el número de documento del socio: ";
    std::cin >> ci;
    //Lectura  cantmascotas
    std::cout << "\tIngrese la cantidad de mascotas: ";
    std::cin >> cantmascotas;
}

void Menu::imprimir_dtmascotas(DataMascota **dtmascotas, int cant) {
    for (int i = 0; i < cant ;++i) {
        dtmascotas[i]->print();
    }
};