#ifndef LIRE_H
#define LIRE_H

#include "../Symbole.h"

class Lire : public Symbole
{
    public:
        Lire();
        virtual ~Lire();

    private:
    	string mot;

};

#endif // LIRE_H