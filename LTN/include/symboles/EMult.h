#ifndef EMULT_H
#define EMULT_H

#include "EBin.h"

class EMult : public EBin
{
    public:
        EMult();
        virtual ~EMult();
		double eval();
    private:

};

#endif // EMULT_H



