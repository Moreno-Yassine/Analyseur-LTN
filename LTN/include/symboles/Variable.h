#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "Symbole.h"
#include "E.h"
#include <map>

using namespace std;
class Valeur;

class Variable : public E
{
    public:
        /* Constructeur par Défaut de la Classe Variable
         * @return : N/A
         */
        Variable();
        Variable(string nom);
		bool setParam(Symbole* symbole, int place);
		string getNom()		{ return nom; };
		bool estAffecte()	{ return (listeValeurs.size()>0); };
		bool affecter(Valeur* valeur,Symbole* lieuAffectation);
		bool estConst();
		void setConst();
		void vider();
		double eval();
		string print();
		bool checkVarPasAffectees();


        virtual ~Variable();

    private:
    	string nom;
		bool constante;
		vector<pair<Symbole*,Valeur*>> listeValeurs;

};

#endif // VARIABLE_H
