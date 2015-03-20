#ifndef PEGL_H
#define PEGL_H

#include "../Symbole.h"
#include <string>

class Pegl : public Symbole
{
    public:
        Pegl();
        virtual ~Pegl();

    private:
    	string mot;

};

#endif // PEGL_H