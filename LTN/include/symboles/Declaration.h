#ifndef DECLARATION_H
#define DECLARATION_H

#include "ID_Symboles.h"
#include "Symbole.h"

class Declaration : public Symbole
{
    public:
        Declaration();
        virtual ~Declaration();
		operator int() const { return idSym; }

		virtual void ajoutSymbole(Symbole* symbole);
		//TODO virtuelle pure
		virtual IdSymbole getIdSymbole();
		//TODO Virtuelle pure
    private:

};

#endif // DECLARATION_H
