cmake_minimum_required(VERSION 3.9)
project(p4_tarea0)

set(CMAKE_CXX_STANDARD 11)

add_executable(p4_tarea0
        Veterinaria/1_PresentationLayer/Controls/Menu.cpp
        Veterinaria/1_PresentationLayer/Controls/Menu.h
        Veterinaria/2_BusinessLayer/BusinessComponents/VeterinariaAdministration.cpp
        Veterinaria/2_BusinessLayer/BusinessComponents/VeterinariaAdministration.h
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Consulta.cpp
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Consulta.h
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Gato.cpp
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Gato.h
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/ListaConsultas.cpp
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/ListaConsultas.h
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/ListaMascotas.cpp
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/ListaMascotas.h
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Mascota.cpp
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Mascota.h
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Perro.cpp
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Perro.h
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Socio.cpp
        Veterinaria/2_BusinessLayer/BusinessEntities/Classes/Socio.h
        Veterinaria/Cross-Cutting/DataTypes/DataConsulta.cpp
        Veterinaria/Cross-Cutting/DataTypes/DataConsulta.h
        Veterinaria/Cross-Cutting/DataTypes/DataGato.cpp
        Veterinaria/Cross-Cutting/DataTypes/DataGato.h
        Veterinaria/Cross-Cutting/DataTypes/DataMascota.cpp
        Veterinaria/Cross-Cutting/DataTypes/DataMascota.h
        Veterinaria/Cross-Cutting/DataTypes/DataPerro.cpp
        Veterinaria/Cross-Cutting/DataTypes/DataPerro.h
        Veterinaria/Cross-Cutting/DataTypes/Fecha.cpp
        Veterinaria/Cross-Cutting/DataTypes/Fecha.h
        Veterinaria/Cross-Cutting/Enums/Genero.h
        Veterinaria/Cross-Cutting/Enums/RazaPerro.h
        Veterinaria/Cross-Cutting/Enums/TipoPelo.h
        Veterinaria/Cross-Cutting/Const.cpp
        Veterinaria/Cross-Cutting/Const.h
        Veterinaria/cambios_listaconsulta,_socio,_add,_agregar_consulta_y_mascota.patch
        Veterinaria/cmake-build-debug.zip
        Veterinaria/CMakeLists.txt
        Veterinaria/main.cpp
        Veterinaria/Makefile
        README.md)
