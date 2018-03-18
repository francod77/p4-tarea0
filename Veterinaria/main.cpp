#include <iostream>
#include "1_PresentationLayer/Controls/Menu.h"
#include "2_BusinessLayer/BusinessComponents/VeterinariaAdministration.h"

int main() {
    VeterinariaAdministration *administration = new VeterinariaAdministration();
    Menu menu = *new Menu();
    int option;

    std::string ci;
    std::string nombre;
    DataMascota*  dataMascota;

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Bienvenido al sistema de administración de Veterinarias" << std::endl;
    std::cout << "-------------------------------------------------------\n\n" << std::endl;
    while (true) {
        menu.showGeneralMenu();
        option = menu.getMenuOption();
        std::string ci;
        switch (option) {
            case 0: {
                std::cout << "Bye." << std::endl;
                return 0;
                break;
            }
            case 1: {
                try {
                    menu.leerOpcionRegistrarSocio(ci, nombre, dataMascota);

                    administration->registrarSocio(ci, nombre, *dataMascota);
                    std::cout << "El socio se registro con éxito." << std::endl;
                }
                catch(std::invalid_argument &error){
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 2: {
                menu.leerOpcionAgregarMascota(ci, dataMascota);
                try {
                    administration->agregarMascota(ci, dataMascota);
                    std::cout << "Se agrego una mascota nueva al socio con éxito." << std::endl;
                }catch(std::invalid_argument &error){
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 3: {
                std::string motivo;
                try{
                    menu.leer_consulta_nueva(motivo, ci);
                 administration->ingresarConsulta(motivo, ci);
                }
                catch(std::invalid_argument &error){
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 4: {
                int cantconsultas;
                Fecha fecha;
                fecha = *new Fecha();
               try{
                   menu.leer_verantesdefecha(fecha, ci, cantconsultas);
                   DataConsulta **lista = administration->verConsultasAntesDeFecha(fecha, ci, cantconsultas);
                   menu.imprimir_dtconsulta(lista, cantconsultas);
                }
                catch(std::invalid_argument &error){
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 5: {
                std::string ci;
                menu.leerOpcionEliminarSocio(ci);
                try {
                    administration->eliminar_socio(ci);
                    std:: cout << "elimando correctamente" <<std::endl;
                }
                catch (std::invalid_argument &error) {

                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 6: {
                int cantmascotas;
                try {
                    menu.leer_obtenermascotas(ci, cantmascotas);//en cantmascotas queda valor ingresado por user
                    DataMascota ** mascotas = administration->obtenerMascotas(ci, cantmascotas);
                    //ahora cantmascotas tiene el largo de la lista de mascotas del socio dado
                    menu.imprimir_dtmascotas(mascotas, cantmascotas);
                }
                catch(std::invalid_argument &error){
                    std::cout << error.what() << std::endl;
                }
                break;
            }
        }
    }
}

