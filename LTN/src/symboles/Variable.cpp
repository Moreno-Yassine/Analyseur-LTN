#include "../../include/symboles/Variable.h"

Variable::Variable(): Symbole(I_ID, "I_ID")
{

}

Variable::Variable(string mot): Symbole(I_ID, "I_ID")
{
	nom = mot;
	affectee = false;
	declaree = false;
}

Variable::~Variable()
{

}

string Variable::print()
{
	return nom;
}

double Variable::eval()
{
	return valeurCourante;
}

bool Variable::setParam(Symbole* symbole, int place)
{
	
	return true;
}
