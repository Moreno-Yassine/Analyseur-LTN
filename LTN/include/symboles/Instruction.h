#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbole.h"

class Instruction : public Symbole
{
    public:
        Instruction();
        virtual ~Instruction();
		double eval();
		bool executer();
    private:

};

#endif // INSTRUCTION_H

