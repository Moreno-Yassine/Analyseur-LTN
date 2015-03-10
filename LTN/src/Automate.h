#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

// typedef pour la map des variables
typedef std::map<std::string, std::string> MapVarNameValue;
typedef map<std::string, std::string>::const_iterator VarMapIterator;
// typedef pour la map des constantes
typedef std::map<std::string, int> MapConstNameValue;
typedef map<std::string, int>::const_iterator ConstMapIterator;

class Automate
{
    public:
        Automate();
        virtual ~Automate();

        bool addVariable(std::string name, std::string value);
        bool addConstante(std::string name, int value);

        void displayConst();
        void displayVar();


    private:
        MapVarNameValue MapVariables;
        MapConstNameValue MapConst;

};

#endif // AUTOMATE_H
