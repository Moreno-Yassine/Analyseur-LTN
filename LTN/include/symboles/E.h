#ifndef E_H
#define E_H

#include "Symbole.h"

class E : public Symbole
{
    public:
        E();
        virtual ~E();
		virtual double eval() = 0;
		virtual string print() = 0;
		//TODO

    private:

};

#endif // E_H


