#ifndef IDC_H
#define IDC_H

#include "Symbole.h"
#include <iostream>
#include <sstream>
class Variable;
class Valeur;

class Idc : public Symbole
{
    public:
        Idc();
        virtual ~Idc();
		bool executer();
		Variable* getVariable();
		Valeur* getValeur();
		bool setParam(Symbole* symbole, int noPlace);
		string print();

    private:
		Variable* variable;
		Valeur* valeur;
		vector<Variable*> listeVariables;
		vector<Valeur*> listeValeurs;
};

#endif // IDC_H
