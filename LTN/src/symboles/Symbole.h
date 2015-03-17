#ifndef SYMBOLE_H
#define SYMBOLE_H

#include "ID_Symboles.h"

class Symbole
{
    public:
        Symbole();
        virtual ~Symbole();
		operator int() const { return idSym; }

    private:
		IdSymbole idSym;

};

#endif // SYMBOLE_H
