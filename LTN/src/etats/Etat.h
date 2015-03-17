#ifndef ETAT_H
#define ETAT_H

#include <iostream>
#include "../Automate.h"

using namespace std;

class Etat
{
    public:
        Etat(string nom);
		virtual bool transition(Automate &automate, Symbole* symbole) = 0;
        virtual ~Etat();

    private:
        std::string nom;

};

#endif // ETAT_H
