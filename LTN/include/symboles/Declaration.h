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

		void ajoutSymbole(Symbole* symbole);
		IdSymbole getIdSymbole();

		bool executer();
		Variable* trouver(string nomVariable);
    
	private:
		
};

#endif // DECLARATION_H
