#ifndef EPLUS_H
#define EPLUS_H

#include "EBin.h"
class Symbole;

class EPlus : public EBin
{
    public:
        EPlus();
        virtual ~EPlus();
		string print();
		double eval();
		bool setParam(Symbole* symbole, int noPlace);

    private:
		E* exprGauche;
		E* exprDroite;
};

#endif // EPLUS_H




