#ifndef EMULT_H
#define EMULT_H

#include "EBin.h"
class Symbole;

class EMult : public EBin
{
    public:
        EMult();
        virtual ~EMult();
		string print();
		double eval();
		bool setParam(Symbole* symbole, int noPlace);
    private:
		E* exprGauche;
		E* exprDroite;
};

#endif // EMULT_H



