#ifndef MUL_H
#define MUL_H

#include "../Symbole.h"
#include <string>

class Mul : public Symbole
{
    public:
        Mul();
        virtual ~Mul();

    private:
    	string mot;

};

#endif // MUL_H