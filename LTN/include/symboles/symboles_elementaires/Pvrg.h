#ifndef PVRG_H
#define PVRG_H

#include "../Symbole.h"
#include <string>

class Pvrg : public Symbole
{
    public:
        Pvrg();
        virtual ~Pvrg();

    private:
    	string mot;

};

#endif // PVRG_H