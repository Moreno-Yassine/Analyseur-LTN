#ifndef EBIN_H
#define EBIN_H

#include "E.h"
class Symbole;

class EBin : public E
{
    public:
        EBin();
        virtual ~EBin();
		string print();
		double eval();
		bool setParam(Symbole* symbole, int noPlace);

    private:

};

#endif // EBIN_H



