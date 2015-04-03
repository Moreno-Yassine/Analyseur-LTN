#ifndef EMULT_H
#define EMULT_H

#include "EBin.h"
#include "OpM.h"
class Symbole;

class EMult : public EBin
{
    public:
        /* Constructeur par Défaut de la Classe EMult
         * @return : N/A
         */
        EMult();
        virtual ~EMult();
		string print();
		double eval();
		bool setParam(Symbole* symbole, int noPlace);
		bool checkVarPasAffectees();
    private:
		E* exprGauche;
		E* exprDroite;
		opM* operateurMult;
};

#endif // EMULT_H



