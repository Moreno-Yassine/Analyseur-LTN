#ifndef ETATS_H
#define ETATS_H

#include <iostream>
#include "Etat.h"
//#include "../Automate.h"
#include "../symboles/Programme.h"
#include "../symboles/Ld.h"

using namespace std;
class Automate;
/* ------- Etat 0  --------
 * 
 * ------------------------
 */
class E0 : public Etat
{
    public:
		E0():Etat("E0"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E0();

    private:
        std::string nom;

};

#endif // ETATS_H
