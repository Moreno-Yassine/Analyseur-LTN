#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <string>
#include <map>

using namespace std;

class Automate
{
    public:
        Automate();
        virtual ~Automate();

    private:
        typedef std::map<std::string, std::string> MapNomValue;
        MapNomValue mapConst;
        MapNomValue mapVar;

};

#endif // AUTOMATE_H
