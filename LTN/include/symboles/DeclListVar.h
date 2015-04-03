#ifndef DECLLISTVAR_H
#define DECLLISTVAR_H

#include "Declaration.h"

class Idv;
class DeclListVar : public Declaration
{
    public:
        /* Constructeur par Défaut de la Classe DeclListVar
         * @return : N/A
         */
        DeclListVar();
        virtual ~DeclListVar();
		bool executer();
		bool setParam(Symbole* symbole, int noPlace);
		Variable* trouver(string nomVariable);
		string print();
		vector<Variable*> getVariables();

    private:
		vector<Idv*> listeVarDeclareesIci;
};

#endif // DECLLISTVAR_H


