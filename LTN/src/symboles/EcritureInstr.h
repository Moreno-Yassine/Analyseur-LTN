#ifndef EcritureINSTRUCTION_H
#define EcritureINSTRUCTION_H

#include "Symbole.h"
class Instruction;

class EcritureInstr : public Instruction
{
    public:
        EcritureInstr();
        virtual ~EcritureInstr();
		double eval();
    private:

};

#endif // EcritureINSTRUCTION_H
