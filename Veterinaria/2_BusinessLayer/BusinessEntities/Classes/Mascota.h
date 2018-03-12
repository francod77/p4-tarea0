//
// Created by juanr on 11/3/2018.
//

#ifndef VETERINARIA_MASCOTA_H
#define VETERINARIA_MASCOTA_H


#include <string>
#include "../../../Cross-Cutting/Enums/Genero.h"

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

    void setRacionDiaria(float racionDiaria);
};


#endif //VETERINARIA_MASCOTA_H
