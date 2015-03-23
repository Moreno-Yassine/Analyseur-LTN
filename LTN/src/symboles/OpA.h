#ifndef OPA_H
#define OPA_H

#include "Symbole.h"

class opA : public Symbole
{
    public:
		opA() : Symbole(I_opA, "I_opA") {};
		virtual ~opA() {};
		bool fonctionBidon();

    private:

};

#endif // OPA_H

