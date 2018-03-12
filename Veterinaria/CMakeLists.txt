cmake_minimum_required(VERSION 3.9)
project(Veterinaria)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        Veterinaria main.cpp
        Cross-Cutting/Enums/TipoPelo.h Cross-Cutting/Enums/Genero.h Cross-Cutting/Enums/RazaPerro.h Cross-Cutting/DataTypes/Fecha.cpp
        Cross-Cutting/DataTypes/Fecha.h
        Cross-Cutting/DataTypes/DataConsulta.cpp Cross-Cutting/DataTypes/DataConsulta.h Cross-Cutting/DataTypes/DataMascota.cpp
        Cross-Cutting/DataTypes/DataMascota.h Cross-Cutting/DataTypes/DataPerro.cpp Cross-Cutting/DataTypes/DataPerro.h
        Cross-Cutting/DataTypes/DataGato.cpp Cross-Cutting/DataTypes/DataGato.h
        2_BusinessLayer/BusinessEntities/Classes/Consulta.cpp 2_BusinessLayer/BusinessEntities/Classes/Consulta.h
        2_BusinessLayer/BusinessEntities/Classes/Mascota.cpp 2_BusinessLayer/BusinessEntities/Classes/Mascota.h
        2_BusinessLayer/BusinessEntities/Classes/Gato.cpp 2_BusinessLayer/BusinessEntities/Classes/Gato.h
        2_BusinessLayer/BusinessEntities/Classes/Perro.cpp 2_BusinessLayer/BusinessEntities/Classes/Perro.h
)
