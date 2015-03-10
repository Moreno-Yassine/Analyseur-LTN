#include "Automate.h"

Automate::Automate()
{

}

Automate::~Automate()
{

}

// Add values to maps
bool Automate::addVariable(std::string name, std::string value)
{
    return (MapVariables.insert(std::pair<std::string, std::string>(name, value))).second;
}

bool Automate::addConstante(std::string name, int value)
{
    return (MapConst.insert(std::pair<std::string, int>(name, value))).second;
}

// Display Map Contents
void Automate::displayVar()
{
    cout << "###################### Mappe des variables: " << endl;
    cout << "Const size: " << MapVariables.size() << endl;
    for (VarMapIterator iter = MapVariables.begin(); iter != MapVariables.end(); iter++)
    {
        cout << "Name Value: " << iter->first << endl << "Value:" << iter->second << endl;
    }
        cout << "###################### END Mappe des variables: " << endl;
}

void Automate::displayConst()
{
    cout << "###################### Mappe des contantes: " << endl;
    cout << "Const size: " << MapConst.size() << endl;
    for (ConstMapIterator iter = MapConst.begin(); iter != MapConst.end(); iter++)
    {
        cout << "Name Const: " << iter->first << endl << "Value:" << iter->second << endl;
    }
    cout << "###################### END Mappe des contantes: " << endl;
}