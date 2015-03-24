#ifndef PTHO_H
#define PTHO_H

#include "../Symbole.h"
#include <string>

class Ptho : public Symbole
{
    public:
        Ptho();
        virtual ~Ptho();

    private:
    	string mot;

};

#endif // PTHO_H