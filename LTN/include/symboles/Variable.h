#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "Symbole.h"

using namespace std;

class Variable : public Symbole
{
    public:
        Variable();
        Variable(string nom);
        virtual ~Variable();

    private:
    	string nom;
};

#endif // VARIABLE_H
