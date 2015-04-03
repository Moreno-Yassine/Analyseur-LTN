#ifndef LECTUREINSTRUCTION_H
#define LECTUREINSTRUCTION_H

#include "Symbole.h"
#include "Valeur.h"

class Instruction;
class Variable;

class LectureInstr : public Instruction
{
    public:
        /* Constructeur par Défaut de la Classe LectureInstr
         * @return : N/A
         */
        LectureInstr();
        virtual ~LectureInstr();
		bool setParam(Symbole* symbole, int place);
		string print();
		double eval();
		bool executer();
		bool is_number(const std::string& s);
		bool checkModifiedConst();
		bool checkVarPasAffectees(vector<Variable*> variables);

    private:
		Variable* variableLue;
};

#endif // INSTRUCTION_H

