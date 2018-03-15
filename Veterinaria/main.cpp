#include <iostream>
#include "1_PresentationLayer/Controls/Menu.h"
#include "2_BusinessLayer/BusinessComponents/VeterinariaAdministration.h"

int main() {
    VeterinariaAdministration* administration = new VeterinariaAdministration();
    Menu menu = *new Menu();
    int option;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Bienvenido al sistema de administración de Veterinarias" << std::endl;
    std::cout << "-------------------------------------------------------\n\n" << std::endl;
    while (true) {
        menu.showGeneralMenu();
        option = menu.getMenuOption();
        switch (option){
            case 0:
                std::cout << "Bye." << std::endl;
                return 0;
                break;
            case 1:
                std::string ci;
                std::string nombre;
                DataMascota* dataMascota;
                menu.leerOpcionRegistrarSocio(ci, nombre, dataMascota);
                administration->registrarSocio(ci, nombre, *dataMascota);
                break;
        }
        if (option == 0){
            std::cout << "Bye." << std::endl;
            return 0;
        }
    }

}