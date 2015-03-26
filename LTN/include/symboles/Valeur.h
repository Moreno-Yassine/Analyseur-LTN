#ifndef VALEUR_H
#define VALEUR_H

#include "Symbole.h"
#include <string>

using namespace std;

class Valeur : public Symbole
{
    public:
        Valeur();
        Valeur(string valeur);
        virtual ~Valeur();
		double eval();

    private:
    	double valeur;
};

#endif // VALEUR_H





