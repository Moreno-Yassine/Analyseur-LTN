#ifndef DECLARATION_H
#define DECLARATION_H

#include "ID_Symboles.h"
#include "Symbole.h"

class Variable;


class Declaration : public Symbole
{
    public:
        Declaration();
        virtual ~Declaration();
		operator int() const { return idSym; }

		virtual void ajoutSymbole(Symbole* symbole);
		virtual IdSymbole getIdSymbole();

		virtual bool executer() = 0;
		virtual Variable* trouver(string nomVariable) = 0;
    
	private:
		
};

#endif // DECLARATION_H
