#include "../../include/symboles/Instruction.h"
#include "../../include/symboles/AffectationInstr.h"
#include "../../include/symboles/Variable.h"
#include "../../include/symboles/Valeur.h"
#include "../../include/symboles/E.h"
#include <sstream>

AffectationInstr::AffectationInstr()
{
	expressionAffectee = NULL;
	variableSeFaisantAffecter = NULL;
}

AffectationInstr::~AffectationInstr()
{

}

double AffectationInstr::eval()
{
	return variableSeFaisantAffecter->eval();
}

bool AffectationInstr::setParam(Symbole* symbole, int place)
{
	switch(place)
	{
		case 1:
			variableSeFaisantAffecter = (Variable*)symbole;
			break;
		case 2:
			expressionAffectee = (E*)symbole;
			break;
	}
	return true;
}

bool AffectationInstr::executer()
{
	double valeurCourante = expressionAffectee->eval();
	stringstream ss;
	ss<<valeurCourante;
	Valeur* val = new Valeur(ss.str());
	variableSeFaisantAffecter->affecter(val,this);
	return true;
}

string AffectationInstr::print()
{

	cout << "------ AffectationInstr::print()" << endl;

	string retour = variableSeFaisantAffecter->print();
	retour.append(" := ");
	//retour.append(expressionAffectee->print());
	retour.append(";");
	return retour;
}
