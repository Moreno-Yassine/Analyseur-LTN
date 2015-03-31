#ifndef EPARANTHESES_H
#define EPARANTHESES_H

#include "E.h"
class Symbole;

class EParantheses : public E
{
    public:
        EParantheses();
        virtual ~EParantheses();
		string print();
		double eval();
		bool setParam(Symbole* symbole, int noPlace);
		bool checkVarPasAffectees();
    private:
		E* expression;

};

#endif // EPARANTHESES_H




