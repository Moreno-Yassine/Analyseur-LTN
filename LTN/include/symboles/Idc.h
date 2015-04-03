#ifndef IDC_H
#define IDC_H

#include "Symbole.h"
#include <iostream>
#include <sstream>

class Variable;
class Valeur;

class Idc : public Symbole
{
    public:
        /* Constructeur par Défaut de la Classe Idc
         * @return : N/A
         */
        Idc();
        virtual ~Idc();
		bool executer();
		Variable* getVariable();
		Valeur* getValeur();
		bool setParam(Symbole* symbole, int noPlace);
		string print();
		Variable* trouver(string nomConstante);

    private:
		Variable* variable;
		Valeur* valeur;
		vector<Variable*> listeConstantes;
		vector<Valeur*> listeValeurs;
};

#endif // IDC_H
