int main(){

/* Registra un socio con su mascota. El valor el atributo racionDiaria se debe setear en 0.*/
void registrarSocio(string ci, string nombre, const DtMascota& dtMascota){}

 /*Agrega una nueva mascota a un socio ya registrado. 
 Si no existe un socio registrado con esa cédula, se levanta una excepción std::invalid_argument.*/ 
void agregarMascota(string ci, const DtMascota& dtMascota){}

/*Crea una consulta con un motivo para un socio. 
Si no existe un socio registrado con esa cédula, se levanta una excepción std::invalid_argument.*/  
void ingresarConsulta(string motivo, string ci){}

  /*devuelve las consultas antes de cierta fecha. Para poder implementar esta operación se deberá 
  sobrecargar el operador < (menor que) para el DataType Fecha. El largo del arreglo está dado por el parámetro cantConsultas.*/
DtConsulta** verConsultasAntesDeFecha(const DtFecha& Fecha, string ciSocio, int& cantConsultas){}

  /*elimina al socio, sus consultas y sus mascotas. 
  Si no existe un socio registrado con esa cédula, se levanta una excepción std::invalid_argument.*/
void eliminarSocio(string ci) {}

 /* devuelve un arreglo con las mascotas del socio. El largo del arreglo está dado por el parámetro cantMascotas.
    Si no existe un socio registrado con esa cedula, se levanta una excepción std::invalid_argument.*/
DtMascota** obtenerMascotas(string ci, int& cantMascotas){}
