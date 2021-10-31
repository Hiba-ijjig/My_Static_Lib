#include"pch.h"
#include "Vecteur3D.h"
#include "assert.h"
using namespace std;
using namespace vecteur;
Vecteur3D::Vecteur3D(float x, float y, float z)
{
    this->vect[0] = x;
    this->vect[1] = y;
    this->vect[2] = z;
}

void Vecteur3D::print() const
{
    for (int i = 0; i < 3; i++)
    {
        cout << "vect[" << i << "]=" << at(i) << "\n";
    }
}

float Vecteur3D::at(unsigned int i) const
{
    assert(i >= 0 && i < 3);
    try
    {
        if (i < 0 || i >= 3) throw "rang erre";
        return this->vect[i];
    }
    catch (char* e)
    {
        cout << e << endl;
    }
}

bool Vecteur3D::operator==(const Vecteur3D& v) const
{
    bool res = true;
    for (int i = 0; i < 3; i++)
    {
        res = res && (this->at(i) == v.at(i));
    }
    return res;
}

bool Vecteur3D::operator!=(const Vecteur3D& v) const
{
    bool res = !(*this == v);
    return res;
}

float& Vecteur3D::operator[](unsigned int i)
{
    assert(i >= 0 && i < 3);
    try //release
    {
        if (i < 0 || i >= 3) throw "rang erre";
        return this->vect[i];
    }
    catch (char* e)
    {
        cout << e << endl;
    }
}

Vecteur3D* vecteur::Vecteur3D::operator*(int v) const
{
    Vecteur3D* k = new Vecteur3D();
    for (int i = 0; i < 3; i++) k->vect[i] = this->vect[i] * v;
    return k;
}

float vecteur::Vecteur3D::operator*(const Vecteur3D& v) const
{
    float a = 0;
    for (int i = 0; i < 3; i++) a += this->vect[i] * v.vect[i];
    return a;
}

float vecteur::Vecteur3D::operator~() const
{
    float a = 0;
    for (int i = 0; i < 3; i++) a += pow(this->vect[i], 2);
    return sqrt(a);
}

Vecteur3D* vecteur::Vecteur3D::operator^(const Vecteur3D& v) const
{
    Vecteur3D* tmp = new Vecteur3D();
    tmp->vect[0] = this->vect[1] * v.vect[2] - this->vect[2] * v.vect[1];
    tmp->vect[1] = this->vect[2] * v.vect[0] - this->vect[0] * v.vect[2];
    tmp->vect[2] = this->vect[0] * v.vect[1] - this->vect[1] * v.vect[0];
    return tmp;
}

Vecteur3D* vecteur::Vecteur3D::operator+(const Vecteur3D& v) const
{
    Vecteur3D* tmp = new Vecteur3D();
    for (int i = 0; i < 3; i++)
        tmp->vect[i] = this->vect[i] + v.vect[i];
    return tmp;
}

Vecteur3D* vecteur::Vecteur3D::operator/(float v) const
{
    Vecteur3D* tmp = new Vecteur3D();
    for (int i = 0; i < 3; i++) tmp->vect[i] = (this->vect[i] / v);
    return tmp;
}



void vecteur::afficher(Vecteur3D& V)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "vect[" << i << "]=" << V.at(i) << "\n";
    }
}
