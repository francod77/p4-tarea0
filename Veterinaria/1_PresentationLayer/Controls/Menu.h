#ifndef VETERINARIA_MENU_H
#define VETERINARIA_MENU_H


#include "../../Cross-Cutting/DataTypes/DataMascota.h"

class Menu {
private:
public:
    Menu();
    ~Menu();
    void showGeneralMenu();
    int getMenuOption();
    void leerOpcionRegistrarSocio(std::string &ci,std::string &nombre, DataMascota* &dataMascota);
};


#endif //VETERINARIA_MENU_H
