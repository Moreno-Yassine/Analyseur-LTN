#ifndef EBIN_H
#define EBIN_H

#include "E.h"
class Symbole;

class EBin : public E
{
    public:
        EBin();
        virtual ~EBin();
		virtual string print();
		virtual double eval()=0;
		virtual bool setParam(Symbole* symbole, int noPlace);

    private:
		E* exprGauche;
		E* exprDroite;
};

#endif // EBIN_H



