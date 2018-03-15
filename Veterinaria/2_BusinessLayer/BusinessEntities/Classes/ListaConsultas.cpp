//
// Created by juanr on 12/3/2018.
//

#include "ListaConsultas.h"
#include "Consulta.h"

ListaConsultas::ListaConsultas() {
    this->consultas = new Consulta *[MAX_CONSULTAS];
    for (int i = 0; i < MAX_CONSULTAS; i++) {
        this->consultas[i] = nullptr;
    }
    this->length = 0;//Reserve el tamaño en memoria pero no tengo ningún objeto
};

ListaConsultas::~ListaConsultas() {
    for (int i = 0; i < this->length; ++i) {
        delete this->consultas[i];
    }
    delete this->consultas;
};

Consulta *ListaConsultas::get(int num) {
    return this->consultas[num];
};

void ListaConsultas::add(Consulta *consulta) {
    this->consultas[this->length] = consulta;
    this->length++;
};

int ListaConsultas::getlength() {
    return this->length;
};
