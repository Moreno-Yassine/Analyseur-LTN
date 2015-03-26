#ifndef LI_H
#define LI_H

#include "Symbole.h"
#include <vector>
#include "Instruction.h"

class Li : public Symbole
{
    public:
        Li();
        virtual ~Li();
		bool setParam(Symbole* symbole, int noPlace);
		bool executer();

    private:
		vector<Instruction*> listeInstructions;
};

#endif // LI_H



