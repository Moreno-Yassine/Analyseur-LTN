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

		void ajoutSymbole(Symbole* symbole);
		IdSymbole getIdSymbole();
    private:

};

#endif // DECLARATION_H
