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

    private:
    	int nombre;
};

#endif // VALEUR_H





