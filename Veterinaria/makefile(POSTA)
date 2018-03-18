all: main

WARNING= -Wall
CC = g++
CLS= Menu.o Main.o VeterinariaAdministracion.o Consulta.o Gato.o ListaConsultas.o ListaMascotas.o Mascota.o Perro.o Socio.o DataConsulta.o DataGato.o Datamascota.o DataPerro.o Fecha.o Const.o
DIR_clases = 2_BusinessLayer/BusinessEntities/Classes
DIR_adm = 2_BusinessLayer/BusinessComponents
DIR_control = 1_PresentationLayer/Controls
DIR_data = Cross-Cutting/Datatypes
DIR_enum = Cross-Cutting/Enums
DIR_Const = Cross-Cutting
ODIR = obj
CCFLAGS = -Wall -Werror -I$(DIR_enum DIR_clases DIR_adm DIR_data DIR_control DIR_Const)
OS= $(MODULOS:%=(ODIR)/%.o)


#CCFLAGS_control =  -Wall -Werror -I$(HDIR_control) -g

$(ODIR)/$(Main).o:$(Main).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: (DIR_clases)%.cpp $(DIR_clases)%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: (DIR_data)%.cpp $(DIR_data)%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: (DIR_control)%.cpp $(DIR_control)%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: (DIR_adm)%.cpp $(DIR_adm)%.h
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/%.o: (DIR_enum)%.cpp $(DIR_adm)%.h
	$(CC) $(CCFLAGS) -c $< -o $@

obj/Const.o: Cross-Cutting/Const.h Cross-Cutting/Const.cpp
	$(CC) $(CCFLAGS) -c $< -o $@



Main.o:  $(ODIR)/Main.o $(OS)
	$(CC) $(CCFLAGS) -c $< -o $@

