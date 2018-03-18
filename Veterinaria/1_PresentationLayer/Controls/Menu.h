#ifndef VETERINARIA_MENU_H
#define VETERINARIA_MENU_H


#include "../../Cross-Cutting/DataTypes/DataMascota.h"
#include "../../Cross-Cutting/DataTypes/Fecha.h"
#include "../../Cross-Cutting/DataTypes/DataConsulta.h"

class Menu {
private:
public:
    Menu();
    ~Menu();
    void showGeneralMenu();
    int getMenuOption();
    void leerOpcionRegistrarSocio(std::string &ci,std::string &nombre,  DataMascota* &dataMascota);
    void leerOpcionAgregarMascota(std::string &ci, DataMascota* &dataMascota);
    void leer_consulta_nueva(std::string &motivo, std::string &ci);
    void leer_verantesdefecha(Fecha & fecha,std::string & ci,int &cantconsulta);
    void imprimir_dtconsulta(DataConsulta** dtcons,int cantconsultas);
    void leer_obtenermascotas(std::string &ci,int &cantmascotas);
    void imprimir_dtmascotas(DataMascota** &dtmascotas,int cant);
    void leerOpcionEliminarSocio(std::string &ci);
};


#endif //VETERINARIA_MENU_H
