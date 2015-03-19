#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "E.h"

using namespace std;

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
