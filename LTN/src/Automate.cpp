#include "Automate.h"
#include "etats/Etat.h"
#include "etats/Etats.h"

#include <vector>
#include <cstdio>
using namespace std;

Automate::Automate()
{
    pileSymboles = new vector<Symbole*>();
    pileEtats = new vector<Etat*>();
    pileReductions = new vector<Reduction>();
    currentLexer = Lexer();
    this->constructionPileReductions();
}

Automate::~Automate()
{

}

vector<Etat*>* Automate::getPileEtats()
{
    return pileEtats;
}

// Add declaration
bool Automate::addDeclaration(std::string name, Declaration* declaration)
{
    return (tableSymboles.insert(std::pair<std::string, Declaration*>(name, declaration))).second;
}

void Automate::decalage(Symbole* symbole, Etat* etat)
{
	pileSymboles->push_back(symbole);
	pileEtats->push_back(etat);
    currentLexer.shift();
}


void Automate::reductionEmpile(int numeroRegle, Etat* etat)
{
    this->reduction(numeroRegle);
    pileEtats->push_back(etat);
}


void Automate::reduction(int numeroRegle)
{
    Symbole* symbole;
    IdSymbole idSymbole;
    int nombreADepiler;
    if(numeroRegle > 0 && numeroRegle <= (int)pileReductions->size())
    {
        nombreADepiler = (pileReductions->at(numeroRegle - 1)).nbElementsADepiler;
        idSymbole = (pileReductions->at(numeroRegle - 1)).idSymbole;

        switch(idSymbole)
        {
            case I_Pprime : symbole = NULL; break;
            case I_P : symbole = new Programme(); break;
            case I_LD : symbole = new Ld(); break;
            case I_D : symbole = new Declaration(); break;
            case I_Idc : symbole = new Idc(); break;
            case I_Idv : symbole = new Idv(); break;
            case I_E : symbole = new E(); break;
            case I_Li : symbole = new Li(); break;
            case I_I : symbole = new Instruction(); break;
            case I_opA : symbole = new opA(); break;
            case I_opM : symbole = new opM(); break;
            default : symbole = NULL; break;
        }

        if(symbole != NULL)
        {
            //Création du nouveau symbole avec les ancians symboles
            for(int i=nombreADepiler; i>0; i--)
            {
                symbole->ajoutSymbole(pileSymboles->at(pileSymboles->size() - i));
            }

            //Nettoyage des pileSymboles et pileEtats en supprimant nombreADepiler Elements
            for(int i=0; i<nombreADepiler; i++)
            {
                pileSymboles->pop_back();
                pileEtats->pop_back();
            }

            //Ajout du nouveau symbole dans la pileSymboles
            pileSymboles->push_back(symbole);
        }
    }
    else
    {
        nombreADepiler = 0;
        idSymbole = I_NULL;
    }
}

// Display Map Contents
void Automate::displayMap()
{
    cout << "###################### Mappe des declarations: " << endl;
    cout << "Const size: " << tableSymboles.size() << endl;
    for (StringDeclarationMapIterator iter = tableSymboles.begin(); iter != tableSymboles.end(); iter++)
    {
        cout << "Name Value: " << iter->first << endl << "Value:" /*<< iter->second */<< endl;
    }
        cout << "###################### END Mappe des variables: " << endl;
}

void Automate::constructionPileReductions()
{
    pileReductions->clear();
	
    Reduction reduction;

    //Pour R1 : P' -> P
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Pprime;
    pileReductions->push_back(reduction);

    //Pour R2 : P -> Ld Li
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R3 : Ld -> Ld D ;
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_LD;
    pileReductions->push_back(reduction);

    //Pour R4 : Ld -> Epsilone
    reduction.nbElementsADepiler = 0;
    reduction.idSymbole = I_LD;
    pileReductions->push_back(reduction);

    //Pour R5 : D -> const Idc
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_D;
    pileReductions->push_back(reduction);

    //Pour R6 : D -> var Idv
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_D;
    pileReductions->push_back(reduction);

    //Pour R7 : Idc -> Idc , id = 
    reduction.nbElementsADepiler = 5;
    reduction.idSymbole = I_Idc;
    pileReductions->push_back(reduction);

    //Pour R8 : Idc -> id = nb
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_Idc;
    pileReductions->push_back(reduction);

    //Pour R9 : Idv -> Idv , id
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_Idv;
    pileReductions->push_back(reduction);

    //Pour R10 : Idv -> id
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Idv;
    pileReductions->push_back(reduction);

    //Pour R11 : Li -> Li I
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_Li;
    pileReductions->push_back(reduction);

    //Pour R12 : Li -> Epsilone
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Li;
    pileReductions->push_back(reduction);

    //Pour R13 : I -> lire id
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R14 : I -> ecrire E
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R15 : I -> id := E
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R16 : E -> id
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R17 : E -> nb
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R18 : E -> E opA E
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R19 : E -> E opM E
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R20 : E -> ( E )
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R21 : opA -> pls
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_opA;
    pileReductions->push_back(reduction);

    //Pour R22 : opA -> mns
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_opA;
    pileReductions->push_back(reduction);

    //Pour R23 : opM -> div
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_opM;
    pileReductions->push_back(reduction);

    //Pour R24 : opM -> mul
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_opM;
    pileReductions->push_back(reduction);
}


void Automate::lecture(vector<string> fluxEntrantP)
/* Fonction lecture :
 * 
 */
{
	currentLexer = Lexer(fluxEntrantP);
	bool expressionAcceptee = false;
	Symbole* ptSymboleSuivant;

	// Initialisation de l'automate
	pileEtats->push_back(new E0);

	//Execution de l'automate a pile
	while(!expressionAcceptee)
	{
		ptSymboleSuivant = currentLexer.getNext();
        this->affichageEtatAutomate(ptSymboleSuivant);
		expressionAcceptee = pileEtats->back()->transition(*this, ptSymboleSuivant);
	}
}

void Automate::affichageEtatAutomate(Symbole* symbole)
{
    cout << "Prochain Symbole à lire : " << symbole->toString() << endl;
    
    cout << "Pile Etats : ";
    for (int i=0; i<(int)pileEtats->size(); i++)
    {
        cout << (pileEtats->at(i))->getNomEtat() << " ";
    }
    cout << endl;

    cout << "Pile Symboles : ";

    for (int i=0; i<(int)pileSymboles->size(); i++)
    {
        cout << (pileSymboles->at(i))->toString() << " ";
    }
    cout << endl;
    cout << "Appuyez sur Entrée pour continuer....";
    getchar();

    cout << "\n" << endl;

}