#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbole.h"
#include <iostream>

class Instruction : public Symbole
{
    public:
        Instruction();
        virtual ~Instruction();
		virtual double eval() = 0;
		virtual bool executer() = 0;
		virtual string print() = 0;

    private:

};

#endif // INSTRUCTION_H

