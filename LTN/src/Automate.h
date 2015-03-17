#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symboles/Symbole.h"
#include "symboles/Declaration.h"

#include <string>
#include <map>
#include <vector>
using namespace std;

// typedef pour la map des variables
typedef std::map<std::string, Declaration*> MapStringDeclaration;
typedef map<std::string, Declaration*>::const_iterator StringDeclarationMapIterator;

class Etat;

class Automate
{
    public:
        Automate();
        virtual ~Automate();

        bool addDeclaration(std::string name, Declaration* declaration);

        void displayMap();

		void decalage(Symbole* symbole, Etat* etat);
		/* Permet d'empiler le symbole et l'etat dans la pile de l'automate
		 *
		 */

    private:
        MapStringDeclaration tableSymboles;

        vector<Symbole*>* pileSymboles;
        vector<Etat*>* pileEtats;

};

#endif // AUTOMATE_H
