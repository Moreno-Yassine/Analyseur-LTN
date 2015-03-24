#ifndef LECTUREINSTRUCTION_H
#define LECTUREINSTRUCTION_H

#include "Symbole.h"
class Instruction;

class LectureInstr : public Instruction
{
    public:
        LectureInstr();
        virtual ~LectureInstr();
		double eval();
    private:

};

#endif // INSTRUCTION_H

