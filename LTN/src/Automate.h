#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symboles/Symbole.h"
#include "symboles/Declaration.h"
#include "etats/Etat.h"

#include <string>
#include <map>
#include <vector>

// typedef pour la map des variables
typedef std::map<std::string, Declaration*> MapStringDeclaration;
typedef map<std::string, Declaration*>::const_iterator StringDeclarationMapIterator;

class Automate
{
    public:
        Automate();
        virtual ~Automate();

        bool addDeclaration(std::string name, Declaration* declaration);

        void displayMap();


    private:
        MapStringDeclaration tableSymboles;

        vector<Symbole>* pileSymboles;
        vector<Etat>* pileEtats;

};

#endif // AUTOMATE_H
