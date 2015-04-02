#ifndef EPLUS_H
#define EPLUS_H

#include "EBin.h"
#include "OpA.h"
class Symbole;

class EPlus : public EBin
{
    public:
        EPlus();
        virtual ~EPlus();
		string print();
		double eval();
		bool setParam(Symbole* symbole, int noPlace);
		bool checkVarPasAffectees();

    private:
		E* exprGauche;
		E* exprDroite;
		opA* operateurArithm;
};

#endif // EPLUS_H




