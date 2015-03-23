#ifndef PTHF_H
#define PTHF_H

#include "../Symbole.h"
#include <string>

class Pthf : public Symbole
{
    public:
        Pthf();
        virtual ~Pthf();

    private:
    	string mot;

};

#endif // PTHF_H