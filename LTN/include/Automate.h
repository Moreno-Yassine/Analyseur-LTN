#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symboles/Symbole.h"
#include "symboles/SymbolesComplexes.h"
#include "Lexer.h"

#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <typeinfo>
using namespace std;

// typedef pour la map des variables
typedef std::map<std::string, Declaration*> MapStringDeclaration;
typedef map<std::string, Declaration*>::const_iterator StringDeclarationMapIterator;

class Etat;
class Variable;

struct Reduction
{
	int nbElementsADepiler;
	IdSymbole idSymbole;
};

class Automate
{
    public:
        Automate(map<int, string> &Erreurs);
        virtual ~Automate();

        vector<Etat*>* getPileEtats();
		vector<Symbole*>* getPileSymboles();
		bool addDeclaration(std::string name, Declaration* declaration);
		bool setFile(vector<string> fileVector);
		void decalage(Symbole* symbole, Etat* etat);
		/* Permet d'empiler le symbole et l'etat dans la pile de l'automate
		 * @param : symbole, pointeur sur le symbole qui permet la transition
		 *			etat,	pointeur vers l'etat dans lequel "on va" (on 
		 *					l'empile seulement)
		 * @return : N/A
		 */

		void decalageSansConsommation(Etat* etat);

		void reduction(int numeroRegle);
		/* Permet de réduire une règle est d'empiler le symbole et l'etat dans la pile de l'automate
		 *
		 */

		void constructionPileReductions();

		Programme* lecture();
		/* Permet de faire l'analyse syntaxique d'un liste de string et de
		 * charger sa repr�sentation en memoire
		 * @return : La répresentation mémoire du programme
		 */

		void affichageEtatAutomate(Symbole* symbole);

		Variable* associerIdVariable(Variable* currentVar);
		/* Permet d'associer une variable trouvee dans une expression
		 * a une variable precedemment declaree dans le programme
		 * @param : currentVar, la variable nouvellement creee trouvee dans E
		 * @return: un pointeur vers la variable du programme declaree
		 *			ou vers la nouvelle variable si celle-ci n'existait pas 
		 *			auparavent (ceci genere un warning)
		 */


    private:
        MapStringDeclaration tableSymboles;
		vector<string> fluxEntrantP;
        vector<Symbole*>* pileSymboles;
        vector<Etat*>* pileEtats;
        vector<Reduction>* pileReductions;
        Lexer currentLexer;
		Ld* pointeurDeclarations;
		map<int, string> &erreurs;
		int erreurNb;

};

#endif // AUTOMATE_H
