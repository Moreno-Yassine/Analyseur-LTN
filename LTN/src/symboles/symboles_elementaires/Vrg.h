#ifndef VRG_H
#define VRG_H

#include "../Symbole.h"
#include <string>

class Vrg : public Symbole
{
    public:
        Vrg();
        virtual ~Vrg();

    private:
    	string mot;

};

#endif // VRG_H