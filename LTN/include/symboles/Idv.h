#ifndef IDV_H
#define IDV_H

#include "Symbole.h"
class Variable;


class Idv : public Symbole
{
    public:
        Idv();
        virtual ~Idv();
		bool executer();
		Variable* getVariable();
		bool setParam(Symbole* symbole, int noPlace);

    private:
		Variable* variable;

};

#endif // IDV_H