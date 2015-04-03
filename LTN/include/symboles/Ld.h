#ifndef LD_H
#define LD_H

#include "Symbole.h"
#include "Declaration.h"
#include <vector>
#include <map>
#include <iostream>

class Variable;

class Ld : public Symbole
{
    public:
        /* Constructeur par Défaut de la Classe Ld
         * @return : N/A
         */
        Ld();
        virtual ~Ld();
		bool setParam(Symbole* symbole, int place);
		bool executer();
		bool display();
		Variable* trouver(string nomVariable);

		bool ajouterVariableNonDeclaree(Variable* newVar);

		/* Ld non present permet de specifier, lorsque des variables
		 * sont utilisees dans le programme, que aucune declaration
		 * n'a ete trouvee dans le programme de base et que, en consequence
		 * le ld a ete cree automatiquement par le programme
		 * (dans l'automate avec associerIdVariable par exemple
		 */
		void setLdNonPresent() { nonPresent = true; };
		bool ldNonPresent() {return nonPresent; };
		vector<Variable*> getVariables();


    private:
		vector<Declaration*> listeDeclarations;
		map<string,Variable*> listeVariablesNonDeclarees;
		bool nonPresent;
};

#endif // LD_H




