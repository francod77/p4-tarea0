#ifndef VETERINARIA_MASCOTA_H
#define VETERINARIA_MASCOTA_H


#include <string>
#include "../../../Cross-Cutting/Enums/Genero.h"
#include "../../../Cross-Cutting/DataTypes/DataMascota.h"

class Mascota {
private:
    std::string nombre;
    Genero genero;
    float peso;
    float racionDiaria;
public:
    Mascota();

    Mascota(const std::string &nombre, Genero genero, float peso, float racionDiaria);

    virtual ~Mascota();

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    Genero getGenero() const;

    void setGenero(Genero genero);

    float getPeso() const;

    void setPeso(float peso);

    float getRacionDiaria() const;

    DataMascota* getDataMascota();

    void setRacionDiaria(float racionDiaria);


};


#endif //VETERINARIA_MASCOTA_H
