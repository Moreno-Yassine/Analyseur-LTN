#ifndef VALEUR_H
#define VALEUR_H

#include "Symbole.h"
#include <string>
#include <sstream>
#include "E.h"

using namespace std;

class Valeur : public E
{
    public:
        /* Constructeur par Défaut de la Classe Valeur
         * @return : N/A
         */
        Valeur();
        Valeur(string valeur);
        virtual ~Valeur();
		double eval();
		string print();
		bool setParam(Symbole* symbole,int placeSymbole);
		bool checkVarPasAffectees();

    private:
    	double valeur;
};

#endif // VALEUR_H





