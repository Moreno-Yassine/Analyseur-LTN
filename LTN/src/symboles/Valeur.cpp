#include "Valeur.h"
#include <iostream>
#include <string> 
using namespace std;

Valeur::Valeur()
{
	nombre = 0;
}

Valeur::Valeur(string mot)
{
	nombre = stoi(mot);
}

Valeur::~Valeur()
{

}
