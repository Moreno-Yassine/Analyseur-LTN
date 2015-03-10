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
	automate = new Automate();
}

Controler::~Controler()
{

}

void Controler::configurate (int argc, char ** argv)
{
    // Contr�le du nombre maxi d'arguments
    if (argc > MAX_ARGS)
    {
        throw MaxArgsException;
    }
    // Contr�le mini
    else if (argc == 1)
    {
        com_parser->show_options();
        exit(0);
    }
    //Pr�sence d'arguments
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


    //Test maps MARCO /!\ JE VAIS LE SUPPRIMER!!!!
    //this->testsMapsMarco();

}

//Test maps MARCO /!\ JE VAIS LE SUPPRIMER!!!!
void Controler::testsMapsMarco()
{
    cout << "TEST MARCO" << endl;

    for (int i=0; i<10; i++)
    {
        automate->addVariable("marco"+std::to_string(i), "cane");
    }

    automate->displayVar();

    for (int i=0; i<10; i++)
    {
        automate->addConstante("marco"+std::to_string(i), i);
    }

    automate->displayConst();
}
// Private/static functions

void Controler::enable_o ()
{
    if(!option_o)
    {
        option_o = true;
    }
    else
    {
        throw IllegalArgException;
    }
}

void Controler::enable_p ()
{
    if (!option_p)
    {
        option_p = true;
    }
    else
    {
        throw IllegalArgException;
    }
}

void Controler::enable_e ()
{
    if (!option_e)
    {
        option_e = true;
    }
    else
    {
        throw IllegalArgException;
    }
}

void Controler::enable_a ()
{
    if (!option_a)
    {
        option_a = true;
    }
    else
    {
        throw IllegalArgException;
    }
}

void Controler::analyse_lexsyn()
{
    cout<< "j'execute l'analyse lexsyn :" <<endl;
    string s;
    string exp;
    for(;;)
    {
		cout << "Entrez une expression a tester : " << endl;
		cin >> s;
		cout << "Entrez l'expression attendue : " << endl;
		cin >> exp;
		
		if(s.compare("quit") == 0)
		{
			break;
		}
		
		cout << "Test = " << rules->waitingFor(s,exp) << endl;
	}
    
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
