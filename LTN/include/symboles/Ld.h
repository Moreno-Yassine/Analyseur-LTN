#ifndef LD_H
#define LD_H

#include "Symbole.h"
#include "Declaration.h"
#include <vector>
class Variable;

class Ld : public Symbole
{
    public:
        Ld();
        virtual ~Ld();
		bool setParam(Symbole* symbole, int place);
		bool executer();
		Variable* trouver(string nomVariable);

    private:
		vector<Declaration*> listeDeclarations;
};

#endif // LD_H




