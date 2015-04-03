#ifndef E_H
#define E_H

#include "Symbole.h"

class E : public Symbole
{
    public:
        /* Constructeur par Défaut de la Classe E
         * @return : N/A
         */
        E();
        E(IdSymbole id, string idStr);
        virtual ~E();
		virtual double eval();
		virtual bool checkVarPasAffectees();
		virtual string print();
		virtual bool setParam(Symbole* symbole, int placeSymbole);
		void setId(IdSymbole idSymP, string stringIDP);


};

#endif // E_H


