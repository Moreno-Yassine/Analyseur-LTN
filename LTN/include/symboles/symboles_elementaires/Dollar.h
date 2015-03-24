#ifndef DOLLAR_H
#define DOLLAR_H

#include "../Symbole.h"
#include <string>

class Dollar : public Symbole
{
    public:
        Dollar();
        virtual ~Dollar();

    private:
    	string mot;

};

#endif // DOLLAR_H