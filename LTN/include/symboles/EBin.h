#ifndef EBIN_H
#define EBIN_H

#include "E.h"
class Symbole;

class EBin : public E
{
    public:
        /* Constructeur par Défaut de la Classe EBin
         * @return : N/A
         */
        EBin();
        virtual ~EBin();
		virtual string print();
		double eval();
		bool checkVarPasAffectees();
		virtual bool setParam(Symbole* symbole, int noPlace);

    private:
		E* exprGauche;
		E* exprDroite;
};

#endif // EBIN_H



