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
	if(!variableSeFaisantAffecter->estConst())
	{
		double valeurCourante = expressionAffectee->eval();
		stringstream ss;
		ss<<valeurCourante;
		Valeur* val = new Valeur(ss.str());
		variableSeFaisantAffecter->affecter(val,this);
		return true;

	}else
	{
		cerr << "###Interdit -> \"" << this->print() << "\" - Le programme continue et la constante reste invariée.";
		cerr << endl;

		return false;
	}
}

string AffectationInstr::print()
{
	string retour = variableSeFaisantAffecter->print();
	retour.append(" := ");
	retour.append(expressionAffectee->print());
	retour.append(";");
	return retour;
}

bool AffectationInstr::checkModifiedConst()
{
	if(variableSeFaisantAffecter->estConst())
	{
		cerr << endl << "-------Attention /!\\-----" << endl;
		cerr << "La ligne : \"" << this->print() << "\" cherche à modifier une constante." << endl;
		return true;
	}

	return false;
}

bool AffectationInstr::checkVarPasAffectees(vector<Variable*> variables)
{
	for(int i=0; i<(int)variables.size(); i++)
	{
		if(variableSeFaisantAffecter==variables[i])
		{
			cout << "var Affectee" << endl;
			return true;
		}
	}

	cout <<"var pas affectee" << endl;

	return false;
}
