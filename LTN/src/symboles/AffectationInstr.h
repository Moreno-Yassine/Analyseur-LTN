#ifndef AffectationINSTRUCTION_H
#define AffectationINSTRUCTION_H

#include "Symbole.h"
class Instruction;

class AffectationInstr : public Instruction
{
    public:
        AffectationInstr();
        virtual ~AffectationInstr();
		double eval();
    private:

};

#endif // AffectationINSTRUCTION_H
