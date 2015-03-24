#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbole.h"

class Instruction : public Symbole
{
    public:
        Instruction();
        virtual ~Instruction();
		virtual double eval()=0;
    private:

};

#endif // INSTRUCTION_H

