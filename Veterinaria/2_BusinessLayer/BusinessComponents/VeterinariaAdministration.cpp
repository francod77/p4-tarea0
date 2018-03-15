#include <stdexcept>
#include "VeterinariaAdministration.h"


VeterinariaAdministration::VeterinariaAdministration() {
    this->socios = new Socio *[MAX_SOCIOS];
    for (int i = 0; i < MAX_SOCIOS; i++) {
        this->socios[i] = nullptr;
    }
    this->cantsocios = 0;
};

VeterinariaAdministration::~VeterinariaAdministration() {};

Socio *VeterinariaAdministration::busqueda(std::string ci) {
    int i = 0;
    while (i < this->cantsocios && this->socios[i]->getCi()!=ci) {
        i++;
    };
    if (i < this->cantsocios) {
        return this->socios[i];
    } else {
        throw std::invalid_argument("No existe un socio registrado con esa cédula");
    };
};

void VeterinariaAdministration::registrarSocio(std::string ci, std::string nombre, const DataMascota &dtMascota) {
    Fecha *f = new Fecha(14, 3, 2018);
    Socio *nuevo = new Socio(ci, nombre, *f);
    nuevo->agregar_Mascota(dtMascota);//agregamos la primer mascota
    this->socios[this->cantsocios] = nuevo;
    this->cantsocios++;
};

void VeterinariaAdministration::eliminar_socio(std::string ci) {
    int i = 0;
    while (i < this->cantsocios && this->socios[i]->getCi()!=ci) {
        i++;
    };
    if (i < this->cantsocios) {
        Socio *elsocio = this->socios[i];
        this->socios[i] = this->socios[this->cantsocios - 1];
        this->socios[this->cantsocios - 1] = nullptr;
        this->cantsocios--;
        delete elsocio;
    } else {
        throw std::invalid_argument("No existe un socio registrado con esa cédula");
    }
};

void VeterinariaAdministration::agregarMascota(std::string ci, DataMascota dtmascota) {
    Socio *cliente = busqueda(ci);
    if (cliente != nullptr) {
        cliente->agregar_Mascota(dtmascota);
    } else {
        throw std::invalid_argument("No existe un socio registrado con esa cédula");
    }
};

void VeterinariaAdministration::ingresarConsulta(std::string motivo, std::string ci) {
    Socio *elsocio = busqueda(ci);
    Fecha *f = new Fecha(14, 3, 2018);
    elsocio->agregar_Consulta(motivo, *f);
};

DataConsulta ** VeterinariaAdministration::verConsultasAntesDeFecha(const Fecha &Fecha, std::string ci, int &cantConsultas) {
    Socio *cliente = busqueda(ci);
    return cliente->getConsultasAntesDeFecha(Fecha, cantConsultas);
};

DataMascota **VeterinariaAdministration::obtenerMascotas(std::string ci, int &cantMascotas) {
    Socio *cliente = busqueda(ci);
    //falta implementar la excepcion
    if (cliente != nullptr) {
        return cliente->getListaMascotas();
    } else {
        throw std::invalid_argument("No existe un socio registrado con esa cédula");
    }
};
