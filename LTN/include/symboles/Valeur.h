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
        virtual ~Valeur();
		double eval();

    private:
		string nom;
    	double valeur;
};

#endif // VALEUR_H





