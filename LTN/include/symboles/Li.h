#ifndef LI_H
#define LI_H

#include "Symbole.h"
#include "Instruction.h"
#include "Variable.h"
#include <vector>
#include <iostream>

class Li : public Symbole
{
    public:
        /* Constructeur par Défaut de la Classe Li
         * @return : N/A
         */
        Li();
        virtual ~Li();
		bool setParam(Symbole* symbole, int noPlace);
		bool executer();
		bool display();
		bool checkModifiedConst();
		bool checkVarPasAffectees(vector<Variable*> variables);

    private:
		vector<Instruction*> listeInstructions;
};

#endif // LI_H



