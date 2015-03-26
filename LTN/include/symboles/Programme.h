#ifndef PROGRAMME_H
#define PROGRAMME_H

#include "Symbole.h"
#include "Ld.h"
#include "Li.h"

class Programme : public Symbole
{
    public:
        Programme();
        virtual ~Programme();
		Li* getLi();
		Ld* getLd();
		bool setParam(Symbole* symbole, int place);
		/* setParam de Programme :
		 *		place 1 : Ld,
		 *		place 2 : Li
		 **/

    private:
		Ld* ptLd;
		Li* ptLi;

};

#endif // PROGRAMME_H



