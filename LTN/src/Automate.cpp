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
    for (VarMapIterator iter = MapVariables.begin(); iter != MapVariables.end(); iter++)
    {
        cout << "Name Value: " << iter->first << endl << "Value:" << iter->second << endl;
    }
}

void Automate::displayConst()
{
    for (ConstMapIterator iter = MapConst.begin(); iter != MapConst.end(); iter++)
    {
        cout << "Name Const: " << iter->first << endl << "Value:" << iter->second << endl;
    }
}