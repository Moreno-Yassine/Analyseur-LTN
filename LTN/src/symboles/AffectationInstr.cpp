#include "../../include/symboles/AffectationInstr.h"

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
			if(symbole->toString()== "I_ID")
			{
				expressionAffectee = (Variable*)symbole;
				
			}else if (symbole->toString()== "I_NB")
			{
				expressionAffectee = (Valeur*)symbole;
				
			}else if (symbole->toString()== "I_EPlus")
			{
				expressionAffectee = (EPlus*)symbole;
				
			}else if (symbole->toString()== "I_EMult")
			{	
				expressionAffectee = (EMult*)symbole;
				
			}else if (symbole->toString()== "I_EPar")
			{
				expressionAffectee = (EParantheses*)symbole;
				
			}else
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

	//cout << "------ AffectationInstr::print()" << endl;

	string retour = variableSeFaisantAffecter->print();
	retour.append(" := ");
	retour.append(expressionAffectee->print());
	retour.append(";");
	return retour;
}
