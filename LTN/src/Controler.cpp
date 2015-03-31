#include "../include/Controler.h"
#include "../include/Exceptions.h"

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
	automate = new Automate(erreurs);
	programManager = new ProgramManager();
}

Controler::~Controler()
{
}
/*
Méthode de configuration du controleur
argc : nombre d'arguments en ligne de commande
argv : les arguments
*/
void Controler::configurate(int argc, char ** argv)
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
/*
Méthode principale du controleur, les actions sont executées séquentiellement 
Lecture Fichier -> Analyse lexicale/syntaxique -> RepMémoire -> Affichage -> analyse statique -> Execution
path : chemin du fichier lutin à analyser
*/
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

    memload();

    if (option_p && !option_o)
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
    if (option_o)
    {
        transformation();
    }
}

//<<<<<<<<<< Private/static functions >>>>>>>>>>>>>>>>

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

void Controler::memload()
{
    cout << endl << "##################" << endl << endl;
    cout<<"-----J'execute la representation mémoire..." <<endl;

    automate->setFile(input_file->getContinueParsedFile());

    try
    {
        programManager->setProgram(automate->lecture());
    }
    catch(int i)
    {
        throw SymboleSuivantNonConformeException;
    }
    
    cout<< endl << "-----Répresentation mémoire terminée." <<endl;
    cout << endl << "##################" << endl << endl;

}

void Controler::transformation()
{
    cout << endl << "##################" << endl << endl;
    cout<<"-----J'execute l'optimisation..." <<endl;
    programManager->optimise();
    cout<<endl<<"-----Optimisation terminée." <<endl;
    cout << endl << "##################" << endl << endl;

    if(option_p)
    {
        affichage();
    }

}

void Controler::affichage()
{
    if(!option_o)
    {
        analyse_statique();
    }
    cout << "-----J'affiche le programme..." << endl << endl;

    programManager->displayProgram();
    cout<< endl << "-----Affichage du programme terminée." <<endl;
    cout << endl << "##################" << endl << endl;
}

void Controler::execution()
{
    analyse_statique();
    cout << "-----J'execute le programme..." << endl << endl;

    programManager->execute();
    cout<<endl<<"-----Execution terminée." <<endl;
    cout << endl << "##################" << endl << endl;
}

void Controler::analyse_statique()
{
    cout<<"-----J'execute l'analyse statique..." << endl << endl;
    try
    {
        programManager->analyseStatique(erreurs);
    }
    catch(int i)
    {
        throw SymbolePasDeclarée;
    }

    cout<<endl<<"-----Analyse terminée." <<endl;
    cout << endl << "##################" << endl << endl;
}
