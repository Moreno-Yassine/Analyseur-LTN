#ifndef EcritureINSTRUCTION_H
#define EcritureINSTRUCTION_H

#include "Symbole.h"
#include "EParantheses.h"
#include "EMult.h"
#include "EPlus.h"
#include "Variable.h"
#include "Valeur.h"

class Instruction;
class E;

class EcritureInstr : public Instruction
{
    public:
        EcritureInstr();
        virtual ~EcritureInstr();
		double eval();
		bool executer();
		string print();
        bool setParam(Symbole* symbole, int place);
        bool checkModifiedConst();

    private:
		E* expressionAEcrire;
};

#endif // EcritureINSTRUCTION_H
