#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symboles/Symbole.h"
#include "symboles/Declaration.h"
#include "symboles/IDSymboles.h"

#include <string>
#include <map>
#include <vector>
using namespace std;

// typedef pour la map des variables
typedef std::map<std::string, Declaration*> MapStringDeclaration;
typedef map<std::string, Declaration*>::const_iterator StringDeclarationMapIterator;

class Etat;

struct Reduction
{
	int nbElementsADepiler;
	IDSymboles idSymbole;
};

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

		void reduction(int numeroRegle);
		/* Permet de réduire une règle est d'empiler le symbole et l'etat dans la pile de l'automate
		 *
		 */

		 static void constructionPileReductions();
    private:
        MapStringDeclaration tableSymboles;

        vector<Symbole*>* pileSymboles;
        vector<Etat*>* pileEtats;
        vector<Reduction*>* pileReductions;

};

#endif // AUTOMATE_H
