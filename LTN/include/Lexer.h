#ifndef LEXER_H
#define LEXER_H

#include "symboles/Symbole.h"
#include "Dictionary.h"
#include "symboles/ID_Symboles.h"
#include "symboles/symboles_elementaires/SymbolesElementaires.h"
#include "symboles/Variable.h"
#include "symboles/Valeur.h"

#include <vector>

using namespace std;

class Lexer
{
    public:
        /* Constructeur par Défaut de la Classe Lexer
         * @return : N/A
         */
    	Lexer();

        /* Constructeur par Personnalisé de la Classe Lexer
         * @param : 
         *          fluxCourantP(vector<string>) : Correcpond au mots lu dans le fichier à analyser ;
         * @return : N/A
         */
		Lexer(vector<string> fluxCourantP) 
			:	fluxCourant(fluxCourantP), 
				position(0) 
			{
				rulesDictionary = new Dictionary();
			};

     	/* Destructeur de la Classe Lexer
         * @return : N/A
         */
        virtual ~Lexer();

		/*	Retourne le pointeur sur un symbole terminal suivant (prochain item du flux)
		 *	sans passer au suivant => la lecture n'est pas consommatrice d'un symbole
         * @return : Symbole*
		 */
        Symbole* getNext();

		/*	Passe au symbole suivant dans le flux (Peut eventuellement retourner le symbole)
         * @return : N/A
		 */
		void shift();

        /* Permet de retourner un symbole à partir d'une chaine de caractère
         * @param : 
         *          entree(string) : Mot à parser en symbole ;
         * @return : N/A
         */
		Symbole* getSymbole(string entree);

        /* Permet de retourner le numéri de la ligne courante
         * @return : Integer
         */
		int getNoLigneCourant() { return noLigneCourant; };

		string getTextLu() { return motSuivant; };

    private:
		vector<string> fluxCourant;
		Dictionary* rulesDictionary;
		int position;
		int noLigneCourant;
		string motSuivant;
};

#endif // LEXER_H
