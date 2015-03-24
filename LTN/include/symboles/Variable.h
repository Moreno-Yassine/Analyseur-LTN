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
		bool setParam(Symbole* symbole, int place);
		string print();
        virtual ~Variable();

    private:
    	string nom;
};

#endif // VARIABLE_H
