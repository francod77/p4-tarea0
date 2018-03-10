class DataMascota{
	private:{
		string nombre;
		Genero genero;
		float peso;
		float racionDiaria;
	}
	public:
		void setnombre(string);
		string getnombre();
		void setgenero(Genero);
		Genero getgenero();
		void setpeso(float);
		void setraciondiaria(float peso, string genero); //la racion diaria se calcula segun el peso y el genero(gato o perro)
		float getpeso();
		float getraciondiaria();

}
