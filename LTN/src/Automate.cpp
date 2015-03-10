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
    return (MapVarNameValue.insert(std::pair<std::string, std::string>(name, value))).second;

}

bool Automate::addConstante(std::string name, int value)
{
    return (MapConstNameValue.insert(std::pair<std::string, int>(name, value))).second;

}

// Display Map Contents
void Automate::displayVar()
{
    for (VarMapIterator iter = MapVarNameValue.begin(); iter != MapVarNameValue.end(); iter++)
    {
        cout << "Name Value: " << iter->first << endl << "Value:" << iter->second << endl;
    }
}

void Automate::displayConst()
{
    for (ConstMapIterator iter = MapConstNameValue.begin(); iter != MapConstNameValue.end(); iter++)
    {
        cout << "Name Const: " << iter->first << endl << "Value:" << iter->second << endl;
    }
}