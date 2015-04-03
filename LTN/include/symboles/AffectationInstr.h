#ifndef AffectationINSTRUCTION_H
#define AffectationINSTRUCTION_H

#include "Symbole.h"
#include "Instruction.h"
#include "Variable.h"
#include "Valeur.h"
#include "E.h"
#include "EParantheses.h"
#include "EMult.h"
#include "EPlus.h"

#include <sstream>

class Instruction;
class Variable;
class E;

class AffectationInstr : public Instruction
{
    public:
        /* Constructeur par Défaut de la Classe AffectationInstr
         * @return : N/A
         */
        AffectationInstr();
        virtual ~AffectationInstr();
		double eval();
		bool executer();
		string print();
		bool setParam(Symbole* symbole, int place);
		bool checkModifiedConst();
		bool checkVarPasAffectees(vector<Variable*> variables);

    private:
		Variable* variableSeFaisantAffecter;
		E* expressionAffectee;
};

#endif // AffectationINSTRUCTION_H
