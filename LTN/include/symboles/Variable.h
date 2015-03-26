#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "Symbole.h"
#include <map>

using namespace std;
class Valeur;

class Variable : public Symbole
{
    public:
        Variable();
        Variable(string nom);
		bool setParam(Symbole* symbole, int place);
		string getNom()		{ return nom; };
		bool estAffecte()	{ return (listeValeurs.size()>0); };
		bool affecter(Valeur* valeur,Symbole* lieuAffectation);
		void vider();
		double eval();
		string print();
        virtual ~Variable();

    private:
    	string nom;
		vector<pair<Symbole*,Valeur*>> listeValeurs;

};

#endif // VARIABLE_H
