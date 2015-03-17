#include "Automate.h"

Automate::Automate()
{
    pileSymboles = new vector<Symbole>();
    pileEtats = new vector<Etat>();
}

Automate::~Automate()
{

}

// Add declaration
bool Automate::addDeclaration(std::string name, Declaration* declaration)
{
    return (tableSymboles.insert(std::pair<std::string, Declaration*>(name, declaration))).second;
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
