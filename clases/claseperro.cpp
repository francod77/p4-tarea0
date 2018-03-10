class Perro:public Mascota {
	private:
		Raza raza;
		bool vacunaCachorro;
	public:
		Raza getraza();
		bool getvacuna();
		void setraza(Raza);
		void setvacuna(bool);
};
