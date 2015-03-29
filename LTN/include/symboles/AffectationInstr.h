#ifndef AffectationINSTRUCTION_H
#define AffectationINSTRUCTION_H

#include "Symbole.h"
#include "Instruction.h"
#include "Variable.h"
#include "Valeur.h"
#include "E.h"
#include <sstream>
#include "EParantheses.h"
#include "EMult.h"
#include "EPlus.h"


class Instruction;
class Variable;
class E;

class AffectationInstr : public Instruction
{
    public:
        AffectationInstr();
        virtual ~AffectationInstr();
		double eval();
		bool executer();
		string print();
		bool setParam(Symbole* symbole, int place);

    private:
		Variable* variableSeFaisantAffecter;
		E* expressionAffectee;
};

#endif // AffectationINSTRUCTION_H
