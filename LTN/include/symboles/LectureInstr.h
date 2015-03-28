#ifndef LECTUREINSTRUCTION_H
#define LECTUREINSTRUCTION_H

#include "Symbole.h"
class Instruction;
class Variable;

class LectureInstr : public Instruction
{
    public:
        LectureInstr();
        virtual ~LectureInstr();
		bool setParam(Symbole* symbole, int place);
		string print();
		double eval();
		bool executer();

    private:
		Variable* variableLue;
};

#endif // INSTRUCTION_H

