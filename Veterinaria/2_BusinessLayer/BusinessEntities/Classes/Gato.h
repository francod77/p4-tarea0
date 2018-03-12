//
// Created by juanr on 11/3/2018.
//

#ifndef VETERINARIA_GATO_H
#define VETERINARIA_GATO_H

#include "Mascota.h"
#include "../../../Cross-Cutting/Enums/TipoPelo.h"

class Gato: public Mascota {
private:
    TipoPelo tipoPelo;
public:
    Gato();

    Gato(const std::string &nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo);

    virtual ~Gato();

    TipoPelo getTipoPelo() const;

    void setTipoPelo(TipoPelo tipoPelo);
};


#endif //VETERINARIA_GATO_H
