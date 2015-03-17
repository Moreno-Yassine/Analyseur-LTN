#ifndef ETAT_H
#define ETAT_H

#include <iostream>

using namespace std;

class Etat
{
    public:
        Etat();
        virtual ~Etat();

    private:
        std::string nom;

};

#endif // ETAT_H
