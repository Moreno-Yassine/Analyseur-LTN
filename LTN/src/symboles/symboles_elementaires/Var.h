#ifndef VAR_H
#define VAR_H

#include "../Symbole.h"

class Var : public Symbole
{
    public:
        Var();
        virtual ~Var();

    private:
    	string mot;

};

#endif // VAR_H