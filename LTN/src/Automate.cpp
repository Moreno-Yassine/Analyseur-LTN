#include "Automate.h"
#include "etats/Etat.h"

#include <vector>
using namespace std;

Automate::Automate()
{
    pileSymboles = new vector<Symbole*>();
    pileEtats = new vector<Etat*>();
    pileReductions = new vector<Reduction*>();
    Automate::constructionPileReductions();
}

Automate::~Automate()
{

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
}

void Automate::reduction(int numeroRegle)
{
    Symbole symbole
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

static void constructionPileReductions()
{
    Reduction reduction;

    //Pour R1 :
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Pprime;
    pileReductions->push_back(reduction);

    //Pour R2 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R3 :
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_Ld;
    pileReductions->push_back(reduction);

    //Pour R4 :
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Ld;
    pileReductions->push_back(reduction);

    //Pour R5 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_D;
    pileReductions->push_back(reduction);

    //Pour R6 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_D;
    pileReductions->push_back(reduction);

    //Pour R7 :
    reduction.nbElementsADepiler = 5;
    reduction.idSymbole = I_Idc;
    pileReductions->push_back(reduction);

    //Pour R8 :
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_Idc;
    pileReductions->push_back(reduction);

    //Pour R9 :
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_Idv;
    pileReductions->push_back(reduction);

    //Pour R10 :
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Idv;
    pileReductions->push_back(reduction);

    //Pour R11 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_Li;
    pileReductions->push_back(reduction);

    //Pour R12 :
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Li;
    pileReductions->push_back(reduction);

    //Pour R13 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R14 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R15 :
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R16 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R17 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R18 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R19 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R20 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R21 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R22 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R23 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R24 :
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);
}
