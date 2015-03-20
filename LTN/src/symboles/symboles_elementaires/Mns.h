#ifndef MNS_H
#define MNS_H

#include "../Symbole.h"
#include <string>

class Mns : public Symbole
{
    public:
        Mns();
        virtual ~Mns();

    private:
    	string mot;

};

#endif // MNS_H