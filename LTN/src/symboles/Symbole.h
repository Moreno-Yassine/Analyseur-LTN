#ifndef SYMBOLE_H
#define SYMBOLE_H

#include "ID_Symboles.h"

#include <vector>

using namespace std;

class Symbole
{
    public:
        Symbole();
        Symbole(IdSymbole id);
        virtual ~Symbole();
		operator int() const { return idSym; }

		void ajoutSymbole(Symbole* symbole);
		IdSymbole getIdSymbole();

    protected:
		IdSymbole idSym;
		vector<Symbole*>* symbolesContenus;
};

#endif // SYMBOLE_H
