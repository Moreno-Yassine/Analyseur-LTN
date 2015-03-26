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
		bool estDeclaree() { return declaree; };
		bool estAffectee() { return affectee; };
		void affecterVar() { affectee = true; };
		void declarerVar() { declaree = true; };
		string getNom() { return nom; };
		double eval();
		string print();
        virtual ~Variable();

    private:
    	string nom;
		bool declaree;
		bool affectee;
		double valeurCourante;
};

#endif // VARIABLE_H
