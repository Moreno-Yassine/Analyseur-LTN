#ifndef VARIABLE_H
#define VARIABLE_H

#include "E.h"

class Variable : public E
{
    public:
        Variable();
        Variable(string nom);
        virtual ~Variable();

    private:
    	string nom;
};

#endif // VARIABLE_H
