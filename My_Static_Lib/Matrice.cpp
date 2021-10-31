#include "pch.h"
#include "Matrice.h"
#include <iostream>
#include <assert.h>
using namespace traitMatrice;
using namespace std;

Matrice::Matrice(unsigned int i, unsigned int j)
{

    try
    {
        if (i <= 0 || j <= 0) throw "le nombre de ligne et de colonne doivent être strictement positifs";
        this->lig = i;
        this->col = j;
        this->mat = new int* [this->lig];
        for (int i = 0; i < this->lig; i++) this->mat[i] = new int[this->col];
        for (int i = 0; i < this->lig; i++)
            for (int j = 0; j < this->col; j++)
                this->mat[i][j] = 0;
    }
    catch (char* e)
    {
        cout << e << endl;
    }
}

Matrice::~Matrice()
{
    for (int i = 0; i < this->lig; i++) delete this->mat[i];
    delete this->mat;
}

void Matrice::remplissage(int k)
{
    for (int i = 0; i < this->lig; i++)
        for (int j = 0; j < this->col; j++)
            this->mat[i][j] = k;
}


Matrice* Matrice::operator+(const Matrice& m) const
{
    /*try
   {
       if (this->lig!= m.lig || this->col !=m.lig) throw "Les deux matrices n'ont pas la même taille";
   }
   catch (string e)
   {
       cout << e << endl;
   }*/
    Matrice* tmp = new Matrice(this->lig, this->col);

    assert(this->lig == m.lig && this->col == m.col);
    for (int i = 0; i < this->lig; i++)
        for (int j = 0; j < this->col; j++)
            tmp->mat[i][j] = this->mat[i][j] + m.mat[i][j];
    return tmp;
}

Matrice* Matrice::operator-(const Matrice& m)const
{
    try
    {
        if (this->lig != m.lig || this->col != m.col) throw "Les deux matrices n'ont pas la même taille";
        Matrice* tmp = new Matrice(this->lig, this->col);
        for (int i = 0; i < this->lig; i++)
            for (int j = 0; j < this->col; j++)
                tmp->mat[i][j] = this->mat[i][j] - m.mat[i][j];
        return tmp;
    }
    catch (char* e)
    {
        cout << e << endl;
    }
}

Matrice* Matrice::operator*(const Matrice& m) const
{
    try
    {
        if (this->col != m.lig) throw "Le nombre de ligne de la matrice doit être le même que le nombre de colonne de la matrice courante";
        Matrice* tmp = new Matrice(this->lig, m.col);
        for (unsigned int i = 0; i < this->lig; i++)
            for (unsigned int j = 0; j < m.col; j++)
            {
                tmp->mat[i][j] = 0;
                for (unsigned int k = 0; k < this->col; k++)
                    tmp->mat[i][j] += this->mat[i][k] * m.mat[k][j];
            }
        return tmp;
    }
    catch (char* e)
    {
        cout << e << endl;
    }
}

void traitMatrice::Matrice::operator*(int k) const
{
    for (int i = 0; i < this->lig; i++)
        for (int j = 0; j < this->col; j++) this->mat[i][j] *= k;
}

void Matrice::print() const
{
    for (int i = 0; i < this->lig; i++)
    {
        cout << "\n";
        for (int j = 0; j < this->col; j++) cout << this->mat[i][j];
    }
}
