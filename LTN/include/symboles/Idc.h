#ifndef IDC_H
#define IDC_H

#include "Symbole.h"
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

    private:
		Variable* variable;
		Valeur* valeur;
};

#endif // IDC_H
