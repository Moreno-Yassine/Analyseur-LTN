#ifndef DECLARATION_H
#define DECLARATION_H

#include "ID_Symboles.h"
#include "Symbole.h"
#include <iostream>

class Variable;


class Declaration : public Symbole
{
    public:
        /* Constructeur par Défaut de la Classe Declaration
         * @return : N/A
         */
        Declaration();
        virtual ~Declaration();
		virtual operator int() const { return idSym; }

		virtual void ajoutSymbole(Symbole* symbole);
		virtual IdSymbole getIdSymbole();

		virtual bool executer() = 0;
		virtual string print() = 0;
		virtual Variable* trouver(string nomVariable) = 0;
		virtual vector<Variable*> getVariables() = 0;
    
	private:
		
};

#endif // DECLARATION_H
