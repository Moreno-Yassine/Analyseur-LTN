#ifndef IDV_H
#define IDV_H

#include "Symbole.h"
class Variable;


class Idv : public Symbole
{
    public:
        /* Constructeur par Défaut de la Classe Idv
         * @return : N/A
         */
        Idv();
        virtual ~Idv();
		bool executer();
		Variable* getVariable();
		bool setParam(Symbole* symbole, int noPlace);
		string print();
		Variable* trouver(string nomVariable);
		vector<Variable*> getVariables();

    private:
		Variable* variable;
		vector<Variable*> listeVariables;

};

#endif // IDV_H
