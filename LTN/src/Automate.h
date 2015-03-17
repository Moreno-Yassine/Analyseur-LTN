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
		 * @param : symbole, pointeur sur le symbole qui permet la transition
		 *			etat,	pointeur vers l'etat dans lequel "on va" (on 
		 *					l'empile seulement)
		 * @return : N/A
		 */

		void lecture(vector<string> fluxEntrant);
		/* Permet de faire l'analyse syntaxique d'un liste de string et de
		 * charger sa représentation en memoire
		 * @param : fluxEntrant, contient l'ensemble de l'expression a evaluer
		 */


    private:
        MapStringDeclaration tableSymboles;

        vector<Symbole*>* pileSymboles;
        vector<Etat*>* pileEtats;

};

#endif // AUTOMATE_H
