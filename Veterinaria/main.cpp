#include <iostream>
#include "1_PresentationLayer/Controls/Menu.h"
#include "2_BusinessLayer/BusinessComponents/VeterinariaAdministration.h"
#include "Cross-Cutting/DataTypes/DataGato.h"
#include "Cross-Cutting/DataTypes/DataPerro.h"

template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}


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
                delete administration;
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
                catch (std::invalid_argument &error) {
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 2: {
                menu.leerOpcionAgregarMascota(ci, dataMascota);
                try {
                    administration->agregarMascota(ci, dataMascota);
                    std::cout << "Se agrego una mascota nueva al socio con éxito." << std::endl;
                } catch (std::invalid_argument &error) {
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 3: {
                std::string motivo;
                try {
                    menu.leer_consulta_nueva(motivo, ci);
                    administration->ingresarConsulta(motivo, ci);
                }
                catch (std::invalid_argument &error) {
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 4: {
                int cantconsultas;
                Fecha fecha;
                fecha = *new Fecha();
                try {
                    menu.leer_verantesdefecha(fecha, ci, cantconsultas);
                    DataConsulta **lista = administration->verConsultasAntesDeFecha(fecha, ci, cantconsultas);
                    std::cout << "\t-----------------------------" << std::endl;
                    for (int i = 0; i < cantconsultas; i++) {
                        std::cout<<*lista[i]<<std::endl;
                        //lista[i]->print();
                        std::cout << "\t-----------------------------" << std::endl;
                    }
                }
                catch (std::invalid_argument &error) {
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 5: {
                std::string ci;
                menu.leerOpcionEliminarSocio(ci);
                try {
                    administration->eliminar_socio(ci);
                    std::cout << "elimando correctamente" << std::endl;
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
                    DataMascota **mascotas = administration->obtenerMascotas(ci, cantmascotas);
                    std::cout << "\t-----------------------------" << std::endl;
                    for (int i = 0; i < cantmascotas; i++) {
                        std::cout << *mascotas[i] << std::endl;
                        //mascotas[i]->print();
                        std::cout << "\t-----------------------------" << std::endl;
                    };
                }
                catch (std::invalid_argument &error) {
                    std::cout << error.what() << std::endl;
                }
                break;
            }
            case 7: {
                //primer socio
                administration->registrarSocio("1", "Pedro",
                                               DataGato("Arenita", femenino, 5.0, 5.0 * FACTOR_ALIMENTO_GATO, largo));
                administration->ingresarConsulta("Porque sí", "1");
                administration->ingresarConsulta("Porque tenía ganas", "1");
                administration->ingresarConsulta("Porque se me antojo", "1");

                //segundo socio
                administration->registrarSocio("2", "Roberta",
                                               DataGato("Calamardo", masculino, 25.0, 5.0 * FACTOR_ALIMENTO_GATO,
                                                        mediano));
                administration->ingresarConsulta("No te importa", "2");
                administration->ingresarConsulta("Estaba lloviendo", "2");
                administration->ingresarConsulta("Estaba aburrido", "2");
                //tercer socio
                administration->registrarSocio("3", "Anacleto",
                                               DataGato("SirenoMan", masculino, 5.0, 5.0 * FACTOR_ALIMENTO_GATO,
                                                        largo));
                administration->agregarMascota("3", new DataPerro("ChicoPercebe", masculino, 30.0,
                                                                  10.0 * FACTOR_ALIMENTO_PERRO, labrador, true));
                administration->agregarMascota("3",
                                               new DataPerro("Triton", masculino, 150.0, 10.0 * FACTOR_ALIMENTO_PERRO,
                                                             pitbull, true));
            }
        }
    }
}

