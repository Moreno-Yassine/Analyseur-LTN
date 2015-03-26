#ifndef E_H
#define E_H

#include "Symbole.h"

class E : public Symbole
{
    public:
        E();
        virtual ~E();
		virtual double eval();
		virtual string print();
		//TODO

    private:

};

#endif // E_H


