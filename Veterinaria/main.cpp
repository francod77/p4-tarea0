#include <iostream>
#include "1_PresentationLayer/Controls/Menu.h"
#include "2_BusinessLayer/BusinessComponents/VeterinariaAdministration.h"

int main() {
    VeterinariaAdministration *administration = new VeterinariaAdministration();
    Menu menu = *new Menu();
    int option;

    std::string ci;
    std::string nombre;
    DataMascota *dataMascota;

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
                menu.leerOpcionRegistrarSocio(ci, nombre, dataMascota);
                administration->registrarSocio(ci, nombre, *dataMascota);
                std::cout << "El socio se registro con éxito." << std::endl;
                break;
            }
            case 2: {
                menu.leerOpcionAgregarMascota(ci, dataMascota);
                administration->registrarSocio(ci, nombre, *dataMascota);
                std::cout << "Se agrego una masconta nueva la socio con éxito." << std::endl;
                break;
            }
            case 3: {
                std::string motivo;
                menu.leer_consulta_nueva(motivo, ci);
                administration->ingresarConsulta(motivo, ci);
                break;
            }
            case 4: {
                int cantconsultas;
                Fecha fecha;
                fecha = *new Fecha();
                menu.leer_verantesdefecha(fecha, ci, cantconsultas);
                DataConsulta **lista = administration->verConsultasAntesDeFecha(fecha, ci, cantconsultas);
                //implementar excepcion
                menu.imprimir_dtconsulta(lista, cantconsultas);
                break;
            }
            case 5: {
                std::string ci;
                menu.leerOpcionEliminarSocio(ci);
                try {
                    administration->eliminar_socio(ci);
                }
                catch (std::invalid_argument error) {

                    std::cout << error.what() << std::endl;
                    std::cout << "error 5" << std::endl;
                }
                break;
            }
            case 6: {
                int cantmascotas;
                menu.leer_obtenermascotas(ci, cantmascotas);
                DataMascota **mascotas = administration->obtenerMascotas(ci, cantmascotas);
                menu.imprimir_dtmascotas(mascotas, cantmascotas);
                break;
            }
        }
    }
}

