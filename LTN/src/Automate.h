#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <map>

using namespace std;

// typedef pour la map des variables
typedef std::map<std::string, std::string> MapVarNameValue;
// typedef pour la map des constantes
typedef std::map<std::string, int> MapConstNameValue;

class Automate
{
    public:
        Automate();
        virtual ~Automate();

    private:
        MapNomValue MapVarNameValue;
        MapNomValue MapConstNameValue;


};

#endif // AUTOMATE_H
