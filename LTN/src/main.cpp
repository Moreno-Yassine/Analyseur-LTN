#include <iostream>
#include <string>

#include "Controler.h"

using namespace std;

int main(int argc, char** argv)
{
    Controler ctr;
    try
    {
        ctr.configurate(argc,argv);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

return 0;
}
