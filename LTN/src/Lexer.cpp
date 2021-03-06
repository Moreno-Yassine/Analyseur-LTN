#include "../include/Lexer.h"

#include <string>
using namespace std;

Lexer::Lexer()
{
	noLigneCourant = 1;
	motSuivant = "";
}

Lexer::~Lexer()
{
}

Symbole* Lexer::getNext()
{
	IdSymbole idSymbole = I_NULL;

	if(position >= (int)fluxCourant.size())
	{
		return new Dollar();
	}
	
	//On essaye de reconnaitre le Symbole actuellement lu
	while(idSymbole == I_NULL && position < (int)fluxCourant.size())
	{
		
		motSuivant = fluxCourant[position];
		idSymbole = rulesDictionary->checkWord(motSuivant);

		if(idSymbole == I_NULL)
		{
			position++;
		}
	}
	
	//Création du symbole à partir du Symbole déterminé
	switch(idSymbole)
	{
		case I_pls: return new Pls(); break;
		case I_mns: return new Mns(); break;
		case I_mul: return new Mul(); break;
		case I_div: return new Div(); break;
		case I_egl: return new Egl(); break;
		case I_ptho: return new Ptho(); break;
		case I_pthf: return new Pthf(); break;
		case I_pegl: return new Pegl(); break;
		case I_pvrg:
			noLigneCourant++;
			return new Pvrg(); break;
		case I_vrg: return new Vrg(); break;
		case I_const: return new Const(); break;
		case I_VAR: return new Var(); break;
		case I_lire: return new Lire(); break;
		case I_ecrire: return new Ecrire(); break;
		case I_ID: return new Variable(motSuivant); break;
		case I_NB: return new Valeur(motSuivant); break;
		default: return NULL; break;
	}
}

void Lexer::shift()
{
	position++;
}

