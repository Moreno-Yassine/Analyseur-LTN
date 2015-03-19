#ifndef LEXER_H
#define LEXER_H
#include "symboles/Symbole.h"
#include "Dictionary.h"
#include <vector>

using namespace std;

class Lexer
{
    public:
		Lexer(vector<string> fluxCourantP) 
			:	fluxCourant(fluxCourantP), 
				position(0) 
			{};
		/* Prend en parametre le flux que l'on veut analyser
		 */

        virtual ~Lexer();

        Symbole* getNext();
		/*	Retourne le POINTEUR SUR (????) symbole terminal suivant (prochain item du flux)
		 *	sans passer au suivant
		 */

		void shift();
		/*	Passe au symbole suivant dans le flux
		 *	(Peut eventuellement retourner le symbole)
		 */

		Symbole* getSymbole(string entree);

    private:
		vector<string> fluxCourant;
		int position;
};

#endif // LEXER_H
