#pragma once
#include <iostream>
namespace vecteur {
	class Vecteur3D
	{
	private:
		float vect[3];
	public:
		Vecteur3D(float x = 0.0, float y = 0.0, float z = 0.0);//constructeur
		Vecteur3D(const Vecteur3D& a) = delete;//constructeur de recopie (delete pour ne pas travailler nik avec le constructeur par default ni avec celui ci
		Vecteur3D& operator=(const Vecteur3D& a) = delete;//operateur d'affectation
		void print() const; //afficher les information du vecteur
		float at(unsigned int i) const; //retourner ce qui est dans la case i (different du get/set)
		bool operator==(const Vecteur3D& v) const;//(passage par réfference pour protéger l'objet v')
		bool operator!=(const Vecteur3D& v) const;
		float& operator[](unsigned int i);// retourner et(ou) modifier la valeur
		// la différence entre at et [] est le passage par réference qui offre la possibilité de modifier la valeur existe dans la case i
		friend void afficher(Vecteur3D& V);//-5
		Vecteur3D* operator*(int v) const;//produit par un entier
		float operator*(const Vecteur3D& v) const;//produit scalaire
		float operator~() const;// le module d'un vecteur
		Vecteur3D* operator^(const Vecteur3D& v) const;//produit scalaire
		Vecteur3D* operator+(const Vecteur3D& v) const;//la somme 
		Vecteur3D* operator/(float v) const;// division par un entier
	};
	void afficher(Vecteur3D& V);
}