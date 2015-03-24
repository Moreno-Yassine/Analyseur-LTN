#include "../../include/symboles/Declaration.h"

Declaration::Declaration() : Symbole(I_D, "I_D")
{

}

Declaration::~Declaration()
{

}

IdSymbole Declaration::getIdSymbole()
{
	return this->idSym;
}

void Declaration::ajoutSymbole(Symbole * symbole)
{

}