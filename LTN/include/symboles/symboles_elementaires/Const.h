#ifndef CONST_H
#define CONST_H

#include "../Symbole.h"
#include <string>

class Const : public Symbole
{
    public:
        Const();
        virtual ~Const();

    private:
    	string mot;

};

#endif // CONST_H



