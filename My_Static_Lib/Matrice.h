#pragma once
namespace traitMatrice {

	class Matrice
	{
	private:
		unsigned int col;
		unsigned int lig;
		int** mat;
	public:
		Matrice(unsigned int i, unsigned int j);//constructeur
		Matrice(const Matrice& m) = delete;//constructeur de recopie
		~Matrice();// destructeur
		void remplissage(int k);// remplire la matrice
		Matrice& operator=(const Matrice& m) = delete;
		Matrice* operator+(const Matrice& m) const;
		Matrice* operator-(const Matrice& m) const;
		Matrice* operator*(const Matrice& m) const;
		void operator*(int k) const;// multiplication par un entier
		void print() const;// afficher la patrice
	};

}