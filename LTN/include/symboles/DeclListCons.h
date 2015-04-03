#ifndef DECLLISTCONS_H
#define DECLLISTCONS_H

#include "Declaration.h"

class Idc;
class DeclListCons : public Declaration
{
    public:
        /* Constructeur par Défaut de la Classe DeclListCons
         * @return : N/A
         */
        DeclListCons();
        virtual ~DeclListCons();
		bool executer();
		bool setParam(Symbole* symbole, int noPlace);
		Variable* trouver(string nomVariable);
		string print();
		vector<Variable*> getVariables();

    private:
		vector<Idc*> listeConstDeclareesIci;
};

#endif // DECLLISTCONS_H



