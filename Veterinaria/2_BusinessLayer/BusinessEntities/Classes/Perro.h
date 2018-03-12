//
// Created by juanr on 11/3/2018.
//

#ifndef VETERINARIA_PERRO_H
#define VETERINARIA_PERRO_H


#include "../../../Cross-Cutting/Enums/RazaPerro.h"
#include "Mascota.h"

class Perro : public Mascota {
private:
    RazaPerro raza;
    bool vacunaCachorro;
public:
    Perro();

    Perro(const std::string &nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza,
          bool vacunaCachorro);

    virtual ~Perro();

    RazaPerro getRaza() const;

    void setRaza(RazaPerro raza);

    bool isVacunaCachorro() const;

    void setVacunaCachorro(bool vacunaCachorro);
};


#endif //VETERINARIA_PERRO_H
