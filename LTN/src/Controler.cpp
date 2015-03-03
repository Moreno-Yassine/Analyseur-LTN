#include "Controler.h"
#include "Exceptions.h"

const char* HELP = "help";
bool Controler::option_o;
bool Controler::option_a;
bool Controler::option_p;
bool Controler::option_e;

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
    // Pas d'arguments (eventuellement help)
    else if (argc == 2)
    {

        if (strcmp(argv[1],HELP) == 0)
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
             com_parser->parsing_options(opt);
        }
        catch (int i)
        {
            throw IllegalArgException;
        }
    }
}

void Controler::run(char* path)
{
	analyse_lexsyn(); // TO DELETE
	try
	{
		input_file->setPath(path);
		input_file->openParse();
	}
	catch (int i)
	{
		throw BadFileException;
	}
    analyse_lexsyn();
    memload();
    if (option_o)
    {
        transformation();
    }
    if (option_p)
    {
        affichage();
    }

    if (option_a)
    {
        analyse_statique();
    }
    if (option_e)
    {
        execution();
    }
}

// Private/static functions

void Controler::enable_o ()
{
    option_o = true;
}

void Controler::enable_p ()
{
    option_p = true;
}

void Controler::enable_e ()
{
    option_e = true;
}

void Controler::enable_a ()
{
    option_a = true;
}

void Controler::analyse_lexsyn()
{
    cout<< "j'execute l'analyse lexsyn :" <<endl;
    cout << "Test = " << rules->checkWord("var") << endl;
    
}
void Controler::memload()
{
    cout<<"j'execute la mem representation" <<endl;
}
void Controler::transformation()
{
    cout<<"j'execute la transformation" <<endl;
}
void Controler::affichage()
{
    cout<<"j'execute l'affichage" <<endl;
}
void Controler::execution()
{
    cout<<"j'execute le prog" <<endl;
}
void Controler::analyse_statique()
{
    cout<<"j'execute l'analyse syn" <<endl;
}
