#ifndef OPM_H
#define OPM_H

#include "Symbole.h"

class opM : public Symbole
{
    public:
		opM() : Symbole(I_opM, "I_opM") {};
		virtual ~opM() {};
		string print();
		bool setParam(Symbole* symbole, int noPlace);
		Symbole * getOperateur() { return operateur; };

    private:
		Symbole* operateur;
};

#endif // OPM_H


