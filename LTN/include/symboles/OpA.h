#ifndef OPA_H
#define OPA_H

#include "Symbole.h"

class opA : public Symbole
{
    public:
        /* Constructeur par Défaut de la Classe opA
         * @return : N/A
         */
		opA() : Symbole(I_opA, "I_opA") {};
		virtual ~opA() { delete operateur; };
		string print();
		bool setParam(Symbole* symbole, int noPlace);
		Symbole * getOperateur() { return operateur; };

    private:
		Symbole* operateur;
};

#endif // OPA_H

