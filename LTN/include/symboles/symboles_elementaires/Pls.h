#ifndef PLS_H
#define PLS_H

#include "../Symbole.h"
#include <string>

class Pls : public Symbole
{
    public:
        Pls();
        virtual ~Pls();

    private:
    	string mot;

};

#endif // PLS_H