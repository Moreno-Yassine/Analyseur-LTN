#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbole.h"
#include "Variable.h"
#include <iostream>

class Instruction : public Symbole
{
    public:
        /* Constructeur par Défaut de la Classe Instruction
         * @return : N/A
         */
        Instruction();
        virtual ~Instruction();
		virtual double eval() = 0;
		virtual bool executer() = 0;
		virtual string print() = 0;
		virtual bool checkModifiedConst() = 0;
		virtual bool checkVarPasAffectees(vector<Variable*> variables) = 0;

    private:

};

#endif // INSTRUCTION_H

