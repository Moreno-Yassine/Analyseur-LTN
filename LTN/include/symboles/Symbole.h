#ifndef SYMBOLE_H
#define SYMBOLE_H

#include "ID_Symboles.h"

#include <vector>
#include <string> 

using namespace std;

class Symbole
{
    public:
        Symbole();
        Symbole(IdSymbole id, string idStr);
        virtual ~Symbole();
		operator int() const { return idSym; }

		void ajoutSymbole(Symbole* symbole);
		IdSymbole getIdSymbole();
		string toString();
		void setId(IdSymbole idSymP, string stringIDP);

    protected:
		IdSymbole idSym;
		string stringID;
		vector<Symbole*>* symbolesContenus;
};

#endif // SYMBOLE_H
