#ifndef VALEUR_H
#define VALEUR_H

#include "Symbole.h"
#include <string>

using namespace std;

class Valeur : public Symbole
{
    public:
        Valeur();
        Valeur(string mot);
        Valeur(string mot, double valeur=0);
        virtual ~Valeur();
		double eval();

    private:
		string nom;
    	double valeur;
};

#endif // VALEUR_H





