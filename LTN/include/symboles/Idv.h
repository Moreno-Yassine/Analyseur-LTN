#ifndef IDV_H
#define IDV_H

#include "Symbole.h"
class Variable;


class Idv : public Symbole
{
    public:
        Idv();
        virtual ~Idv();
		bool executer();
		Variable* getVariable();
		bool setParam(Symbole* symbole, int noPlace);
		string print();
		Variable* trouver(string nomVariable);

    private:
		Variable* variable;
		vector<Variable*> listeVariables;

};

#endif // IDV_H
