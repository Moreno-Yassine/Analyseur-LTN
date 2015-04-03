#ifndef ETAT_H
#define ETAT_H

#include <iostream>
#include "../Automate.h"
#include <string>

using namespace std;

class Etat
{
    public:
        /* Constructeur par Défaut de la Classe Etat
         * @return : N/A
         */
		Etat(string nomP) : nom(nomP) {};

        /* Destructeur de la Classe Etat
         * @return : N/A
         */
		virtual ~Etat();
		virtual bool transition(Automate &automate, Symbole* symbole) = 0;
        string getNomEtat();

    private:
        std::string nom;

};

#endif // ETAT_H
