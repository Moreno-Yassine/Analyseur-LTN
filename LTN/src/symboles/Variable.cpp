#include "Variable.h"

Variable::Variable(): Symbole(I_ID, "I_ID")
{

}

Variable::Variable(string mot): Symbole(I_ID, "I_ID")
{
	nom = mot;
}

Variable::~Variable()
{

}

string Variable::print()
{
	return nom;
}
