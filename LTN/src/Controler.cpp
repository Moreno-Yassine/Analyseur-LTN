#include "Controler.h"
#include "Exceptions.h"

Controler::Controler()
{
    input_file = new File();
    rules = new Dictionary();
	com_parser = new Parser();
}

Controler::~Controler()
{

}

void Controler::configurate (int argc, char ** argv)
{
    // Contrôle du nombre maxi d'arguments
    if (argc > MAX_ARGS)
    {
        throw MaxArgsException;
    }
    // Contrôle mini
    else if (argc == 1)
    {
        throw MinArgsException;
    }
    // Pas d'arguments
    else if (argc == 2)
    {
        for (int i=0; i< NUM_OPTIONS; i++)
        {
            configuration[i] = false;
        }
    }
    //Présence d'arguments
    else
    {
        // traiter les arguments présents
    }
}
