#ifndef VETERINARIA_DATAPERRO_H
#define VETERINARIA_DATAPERRO_H


#include "DataMascota.h"
#include "../Enums/RazaPerro.h"

class DataPerro: public DataMascota {
private:
    RazaPerro raza;
    bool vacunaCachorro;
public:
    DataPerro();

    DataPerro(std::string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza,
              bool vacunaCachorro);

    virtual ~DataPerro();

    RazaPerro getRaza() const;

    void setRaza(RazaPerro raza);

    bool isVacunaCachorro() const;

    void setVacunaCachorro(bool vacunaCachorro);

    void print();
};

std::ostream &operator<<(std::ostream &stream, DataPerro dataPerro);

#endif //VETERINARIA_DATAPERRO_H
