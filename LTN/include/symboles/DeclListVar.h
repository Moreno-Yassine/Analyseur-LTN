#ifndef DECLLISTVAR_H
#define DECLLISTVAR_H

#include "Declaration.h"

class Idv;
class DeclListVar : public Declaration
{
    public:
        DeclListVar();
        virtual ~DeclListVar();
		bool executer();
		bool setParam(Symbole* symbole, int noPlace);
		Variable* trouver(string nomVariable);

    private:
		vector<Idv*> listeVarDeclareesIci;
};

#endif // DECLLISTVAR_H


