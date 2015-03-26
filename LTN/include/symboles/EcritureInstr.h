#ifndef EcritureINSTRUCTION_H
#define EcritureINSTRUCTION_H

#include "Symbole.h"
class Instruction;
class E;

class EcritureInstr : public Instruction
{
    public:
        EcritureInstr();
        virtual ~EcritureInstr();
		double eval();
		bool executer();
    private:
		E* expressionAEcrire;
};

#endif // EcritureINSTRUCTION_H
