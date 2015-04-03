#ifndef LI_H
#define LI_H

#include "Symbole.h"
#include <vector>
#include <iostream>
#include "Instruction.h"
#include "Variable.h"

class Li : public Symbole
{
    public:
        Li();
        virtual ~Li();
		bool setParam(Symbole* symbole, int noPlace);
		bool executer();
		bool display();
		bool checkModifiedConst();
		bool checkVarPasAffectees();

    private:
		vector<Instruction*> listeInstructions;
};

#endif // LI_H



