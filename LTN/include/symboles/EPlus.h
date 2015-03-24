#ifndef EPLUS_H
#define EPLUS_H

#include "EBin.h"

class EPlus : public EBin
{
    public:
        EPlus();
        virtual ~EPlus();
		double eval();
    private:

};

#endif // EPLUS_H




