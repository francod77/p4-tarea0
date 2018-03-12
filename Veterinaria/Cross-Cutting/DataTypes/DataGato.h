//
// Created by juanr on 11/3/2018.
//

#ifndef VETERINARIA_DATAGATO_H
#define VETERINARIA_DATAGATO_H


#include "DataMascota.h"
#include "../Enums/TipoPelo.h"

class DataGato: public DataMascota {
private:
    TipoPelo tipoPelo;
public:
    DataGato();

    DataGato(const std::string &nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo);

    virtual ~DataGato();

    TipoPelo getTipoPelo() const;

    void setTipoPelo(TipoPelo tipoPelo);
};


#endif //VETERINARIA_DATAGATO_H
