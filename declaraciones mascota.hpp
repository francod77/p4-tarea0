class Mascota{

	private:
		string nombre;
		Genero genero;
		float peso;
	public:
		float obtenerRacionDiaria();
}

class Gato:public Mascota {
	private:
		TipoPelo tipoPelo;
}

class Perro:public Mascota {
	private:
		Raza raza;
		bool vacunaCachorro;
}


enum RazaPerro
{
	labrador;
	ovejero;
	bulldog;
	pitbull;
	collie;
	pekines;
	otro;
};

enum Genero
{
	Macho;
	Hembra;
};

enum TipoPelo
{
	Corto;
	Mediano;
	Largo;
};