#ifndef E_H
#define E_H

#include "Symbole.h"

class E : public Symbole
{
    public:
        E();
        E(IdSymbole id, string idStr);
        virtual ~E();
		virtual double eval();
		virtual string print();
		virtual bool setParam(Symbole* symbole, int placeSymbole);
		void setId(IdSymbole idSymP, string stringIDP);
		//TODO

    private:

};

#endif // E_H


