#ifndef VETERINARIA_FECHA_H
#define VETERINARIA_FECHA_H


class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha();

    Fecha(int dia, int mes, int anio);

    virtual ~Fecha();

    int getDia() const;

    void setDia(int dia);

    int getMes() const;

    void setMes(int mes);

    int getAnio() const;

    void setAnio(int anio);
};


#endif //VETERINARIA_FECHA_H
