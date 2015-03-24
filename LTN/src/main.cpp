#include <iostream>
#include <string>

#include "../include/Controler.h"

using namespace std;

int main(int argc, char** argv)
{
    Controler ctr;
    try
    {
        ctr.configurate(argc,argv);
        ctr.run(argv[argc-1]);
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
	return 1;
    }

return 0;
}
