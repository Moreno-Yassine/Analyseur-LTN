#ifndef ERREURSSTATIQUES_H
#define ERREURSSTATIQUES_H

#include <string>
using namespace std;

class ErreursStatiques
{
    public:
        static void ValueError(string type, string problem, string valueName);
        static void ModifiedConstant(string valueName);
};

#endif // ERREURSSTATIQUES_H
