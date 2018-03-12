#ifndef VETERINARIA_DATAMASCOTA_H
#define VETERINARIA_DATAMASCOTA_H


#include <string>
#include "../Enums/Genero.h"

class DataMascota {
private:
    std::string nombre;
    Genero genero;
    float peso;
    float racionDiaria;
public:
    DataMascota();

    DataMascota(const std::string &nombre, Genero genero, float peso, float racionDiaria);

    virtual ~DataMascota();

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    Genero getGenero() const;

    void setGenero(Genero genero);

    float getPeso() const;

    void setPeso(float peso);

    float getRacionDiaria() const;

    void setRacionDiaria(float racionDiaria);
};


#endif //VETERINARIA_DATAMASCOTA_H