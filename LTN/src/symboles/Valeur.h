#ifndef VALEUR_H
#define VALEUR_H

#include "E.h"

using namespace std;

class Valeur : public E
{
    public:
        Valeur();
        Valeur(string mot);
        virtual ~Valeur();

    private:
    	int nombre;
};

#endif // VALEUR_H





