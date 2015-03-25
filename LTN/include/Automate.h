#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symboles/Symbole.h"
#include "symboles/SymbolesComplexes.h"
#include "Lexer.h"

#include <string>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

// typedef pour la map des variables
typedef std::map<std::string, Declaration*> MapStringDeclaration;
typedef map<std::string, Declaration*>::const_iterator StringDeclarationMapIterator;

class Etat;

struct Reduction
{
	int nbElementsADepiler;
	IdSymbole idSymbole;
};

class Automate
{
    public:
        Automate();
        virtual ~Automate();

        vector<Etat*>* getPileEtats();

        bool addDeclaration(std::string name, Declaration* declaration);

        void displayMap();

		void decalage(Symbole* symbole, Etat* etat);
		/* Permet d'empiler le symbole et l'etat dans la pile de l'automate
		 * @param : symbole, pointeur sur le symbole qui permet la transition
		 *			etat,	pointeur vers l'etat dans lequel "on va" (on 
		 *					l'empile seulement)
		 * @return : N/A
		 */

		void decalageSansConsommation(Etat* etat);

		void reductionEmpile(int numeroRegle, Etat* etat);

		void reduction(int numeroRegle);
		/* Permet de réduire une règle est d'empiler le symbole et l'etat dans la pile de l'automate
		 *
		 */

		void constructionPileReductions();

		Programme* lecture(vector<string> fluxEntrant);
		/* Permet de faire l'analyse syntaxique d'un liste de string et de
		 * charger sa repr�sentation en memoire
		 * @param : fluxEntrant, contient l'ensemble de l'expression a evaluer
		 * @return : La répresentation mémoire du programme
		 */

		void affichageEtatAutomate(Symbole* symbole);

    private:
        MapStringDeclaration tableSymboles;

        vector<Symbole*>* pileSymboles;
        vector<Etat*>* pileEtats;
        vector<Reduction>* pileReductions;
        Lexer currentLexer;

};

#endif // AUTOMATE_H
