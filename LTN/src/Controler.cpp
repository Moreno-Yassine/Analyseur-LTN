#include "Controler.h"
#include "Exceptions.h"

Controler::Controler()
{
    input_file = new File();
    rules = new Dictionary();
	com_parser = new Parser();
	configuration = new bool[NUM_OPTIONS];
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
    // Pas d'arguments (eventuellement help)
    else if (argc == 2)
    {
        for (int i=0; i< NUM_OPTIONS; i++)
        {
            configuration[i] = false;
        }
        if (argv[1] == "help")
        {
            com_parser->show_options();
        }
    }
    //Présence d'arguments
    else
    {
        vector<string> opt;
        for (int i = 1; i< argc - 1;i++)
        {
            opt.push_back(argv[i]);
        }
        try
        {
             configuration = com_parser->parsing_options(opt);
        }
        catch (int i)
        {
            throw IllegalArgException;
        }

        //TEST
        for (int i=0;i<NUM_OPTIONS;i++)
        {
            cout<<configuration[i]<<endl;
        }

    }
}
