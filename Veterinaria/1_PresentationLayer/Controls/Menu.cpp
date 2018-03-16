#include <string>
#include <iostream>
#include <regex>
#include "Menu.h"
#include "../../Cross-Cutting/DataTypes/DataMascota.h"
#include "../../Cross-Cutting/DataTypes/DataGato.h"
#include "../../Cross-Cutting/DataTypes/DataPerro.h"
#include "../../Cross-Cutting/Const.h"
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

void Menu::leerOpcionEliminarSocio(std::string &ci){
    std::cout<< "Eliminar socio"<<std::endl;
    std::cout << "\tIngrese el número de documento del socio: ";
    std::cin >> ci;
}

void Menu::leerOpcionRegistrarSocio(std::string &ci,std::string &nombre, DataMascota* &dataMascota){

    bool datoValido;
    bool mascotaPerro;
    std::string dato;
    float datoFloat;
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
        if(regex_match(dato,match,std::regex("\\s*(perro|gato)\\s*"))){
            if(regex_match(dato,match,std::regex("\\s*gato\\s*"))){
                dataMascota = new DataGato();
                mascotaPerro = false;
            }else{
                dataMascota = new DataPerro();
                mascotaPerro = true;
            }
            datoValido = true;
        }else{
            std::cout << "\tDato Incorrecto!!!"<< std::endl;
        }
    }

    //Lectura del nombre de la mascota
    std::cout << "\tIngrese el nombre de la mascota del socio: ";
    std::cin >> dato;
    dataMascota->setNombre(dato);

    //Lectura del genero de la mascota
    datoValido = false;
    while (!datoValido){
        std::cout << "\tIndique el genero de la mascota (masculino o femenino): ";
        std::cin >> dato;
        if(regex_match(dato,match,std::regex ("\\s*(masculino|femenino)\\s*"))){
            if(regex_match(dato,match,std::regex ("\\s*masculino\\s*"))){
                dataMascota->setGenero(masculino);
            }else{
                dataMascota->setGenero(femenino);
            }
            datoValido = true;
        }else{
            std::cout << "\tDato Incorrecto!!!"<< std::endl;
        }
    }

    //Lectura del peso de la mascota
    std::cout << "\tIndique el peso de la mascota en kg: ";
    std::cin >> datoFloat;
    dataMascota->setPeso(datoFloat);
    if(mascotaPerro){
        dataMascota->setRacionDiaria(datoFloat * FACTOR_ALIMENTO_PERRO);

        //Lectura raza del perro
        datoValido = false;
        while (!datoValido){
            std::cout << "\tIndique la raza del perro (labrador, ovejero, bulldog, pitbull, collie, pekines u otro: ";
            std::cin >> dato;
            std::regex  r("\\s*(labrador|ovejero|bulldog|pitbull|collie|pekines|otro)\\s*");
            if(regex_match(dato,match,r)){
                if(regex_match(dato,match,std::regex ("\\s*labrador\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(labrador);
                }else if(regex_match(dato,match,std::regex ("\\s*ovejero\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(ovejero);
                }else if(regex_match(dato,match,std::regex ("\\s*bulldog\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(bulldog);
                }else if(regex_match(dato,match,std::regex ("\\s*pitbull\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(pitbull);
                }else if(regex_match(dato,match,std::regex ("\\s*collie\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(collie);
                }else if(regex_match(dato,match,std::regex ("\\s*pekines\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(pekines);
                }else if(regex_match(dato,match,std::regex ("\\s*otro\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(otro);
                }
                datoValido = true;
            }else{
                std::cout << "\tDato Incorrecto!!!"<< std::endl;
            }
        }

        //Lectura vacuna mascota
        datoValido = false;
        while (!datoValido){
            std::cout << "\tIndique si el perro tiene la vacuna de cachorro: ";
            std::cin >> dato;
            std::regex  r("\\s*(si|no)\\s*");
            if(regex_match(dato,match,r)){
                if(regex_match(dato,match,std::regex ("\\s*si\\s*"))){
                    ((DataPerro*)dataMascota)->setVacunaCachorro(true);
                }else{
                    ((DataPerro*)dataMascota)->setVacunaCachorro(false);
                }
                datoValido = true;
            }else{
                std::cout << "\tDato Incorrecto!!!"<< std::endl;
            }
        }
    }else{
        dataMascota->setRacionDiaria(datoFloat * FACTOR_ALIMENTO_GATO);
        //Lectura vacuna mascota
        datoValido = false;
        while (!datoValido){
            std::cout << "\tIndique el tipo de pelo del gato (largo, mediano o corto): ";
            std::cin >> dato;
            std::regex  r("\\s*(largo|mediano|corto)\\s*");
            if(regex_match(dato,match,r)){
                if(regex_match(dato,match,std::regex ("\\s*largo\\s*"))){
                    ((DataGato*)dataMascota)->setTipoPelo(largo);
                }else if(regex_match(dato,match,std::regex ("\\s*mediano\\s*"))){
                    ((DataGato*)dataMascota)->setTipoPelo(mediano);
                }else{
                    ((DataGato*)dataMascota)->setTipoPelo(corto);
                }
                datoValido = true;
            }else{
                std::cout << "\tDato Incorrecto!!!"<< std::endl;
            }
        }
    }
}

void Menu::leerOpcionAgregarMascota(std::string &ci, DataMascota* &dataMascota){
    bool datoValido;
    bool mascotaPerro;
    std::string dato;
    float datoFloat;
    std::smatch match;

    std::cout << "Agregar mascota a socio:" << std::endl;

    //Lectura del documento del socio
    std::cout << "\tIngrese el número de documento del socio: ";
    std::cin >> ci;

    //Lectura del tipo de mascota del socio
    datoValido = false;
    while (!datoValido){
        std::cout << "\tIndique que tipo de mascota va a registrar (gato o perro): ";
        std::cin >> dato;
        if(regex_match(dato,match,std::regex("\\s*(perro|gato)\\s*"))){
            if(regex_match(dato,match,std::regex("\\s*gato\\s*"))){
                dataMascota = new DataGato();
                mascotaPerro = false;
            }else{
                dataMascota = new DataPerro();
                mascotaPerro = true;
            }
            datoValido = true;
        }else{
            std::cout << "\tDato Incorrecto!!!"<< std::endl;
        }
    }

    //Lectura del nombre de la mascota
    std::cout << "\tIngrese el nombre de la mascota del socio: ";
    std::cin >> dato;
    dataMascota->setNombre(dato);

    //Lectura del genero de la mascota
    datoValido = false;
    while (!datoValido){
        std::cout << "\tIndique el genero de la mascota (masculino o femenino): ";
        std::cin >> dato;
        if(regex_match(dato,match,std::regex ("\\s*(masculino|femenino)\\s*"))){
            if(regex_match(dato,match,std::regex ("\\s*masculino\\s*"))){
                dataMascota->setGenero(masculino);
            }else{
                dataMascota->setGenero(femenino);
            }
            datoValido = true;
        }else{
            std::cout << "\tDato Incorrecto!!!"<< std::endl;
        }
    }

    //Lectura del peso de la mascota
    std::cout << "\tIndique el peso de la mascota en kg: ";
    std::cin >> datoFloat;
    dataMascota->setPeso(datoFloat);
    if(mascotaPerro){
        dataMascota->setRacionDiaria(datoFloat * FACTOR_ALIMENTO_PERRO);

        //Lectura raza del perro
        datoValido = false;
        while (!datoValido){
            std::cout << "\tIndique la raza del perro (labrador, ovejero, bulldog, pitbull, collie, pekines u otro: ";
            std::cin >> dato;
            std::regex  r("\\s*(labrador|ovejero|bulldog|pitbull|collie|pekines|otro)\\s*");
            if(regex_match(dato,match,r)){
                if(regex_match(dato,match,std::regex ("\\s*labrador\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(labrador);
                }else if(regex_match(dato,match,std::regex ("\\s*ovejero\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(ovejero);
                }else if(regex_match(dato,match,std::regex ("\\s*bulldog\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(bulldog);
                }else if(regex_match(dato,match,std::regex ("\\s*pitbull\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(pitbull);
                }else if(regex_match(dato,match,std::regex ("\\s*collie\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(collie);
                }else if(regex_match(dato,match,std::regex ("\\s*pekines\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(pekines);
                }else if(regex_match(dato,match,std::regex ("\\s*otro\\s*"))){
                    ((DataPerro*)dataMascota)->setRaza(otro);
                }
                datoValido = true;
            }else{
                std::cout << "\tDato Incorrecto!!!"<< std::endl;
            }
        }

        //Lectura vacuna mascota
        datoValido = false;
        while (!datoValido){
            std::cout << "\tIndique si el perro tiene la vacuna de cachorro: ";
            std::cin >> dato;
            std::regex  r("\\s*(si|no)\\s*");
            if(regex_match(dato,match,r)){
                if(regex_match(dato,match,std::regex ("\\s*si\\s*"))){
                    ((DataPerro*)dataMascota)->setVacunaCachorro(true);
                }else{
                    ((DataPerro*)dataMascota)->setVacunaCachorro(false);
                }
                datoValido = true;
            }else{
                std::cout << "\tDato Incorrecto!!!"<< std::endl;
            }
        }
    }else{
        dataMascota->setRacionDiaria(datoFloat * FACTOR_ALIMENTO_GATO);
        //Lectura vacuna mascota
        datoValido = false;
        while (!datoValido){
            std::cout << "\tIndique si el tipo de pelo del gato: ";
            std::cin >> dato;
            std::regex  r("\\s*(largo|mediano|corto)\\s*");
            if(regex_match(dato,match,r)){
                if(regex_match(dato,match,std::regex ("\\s*largo\\s*"))){
                    ((DataGato*)dataMascota)->setTipoPelo(largo);
                }else if(regex_match(dato,match,std::regex ("\\s*mediano\\s*"))){
                    ((DataGato*)dataMascota)->setTipoPelo(mediano);
                }else{
                    ((DataGato*)dataMascota)->setTipoPelo(corto);
                }
                datoValido = true;
            }else{
                std::cout << "\tDato Incorrecto!!!"<< std::endl;
            }
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

void Menu::imprimir_dtmascotas(DataMascota **&dtmascotas, int cant) {

    for (int i = 0; i < cant ;++i) {
        /*if(typeid(dtmascotas[i]) == typeid(DataPerro)) {
            DataPerro dp = (DataPerro&) dtmascotas[i] ;
            std::cout << dp <<std::endl;
        } else {

            DataGato dg = (DataGato&) dtmascotas[i];
            std::cout << dg << std::endl;
        }*/
        std::cout << dtmascotas[i]  << std::endl;
    }

};
