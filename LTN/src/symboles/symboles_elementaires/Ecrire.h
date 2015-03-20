#ifndef ECRIRE_H
#define ECRIRE_H

#include "../Symbole.h"
#include <string>

class Ecrire : public Symbole
{
    public:
        Ecrire();
        virtual ~Ecrire();

    private:
    	string mot;

};

#endif // ECRIRE_H