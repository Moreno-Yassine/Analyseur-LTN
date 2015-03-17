#ifndef SYMBOLE_H
#define SYMBOLE_H

#include "ID_Symboles.h"

#include <vector>

using namespace std;

class Symbole
{
    public:
        Symbole();
        virtual ~Symbole();
		operator int() const { return idSym; }

		void ajoutSymbole(Symbole* symbole);

    private:
		IdSymbole idSym;
		vector<Symbole*>* symbolesContenus;
};

#endif // SYMBOLE_H
