#ifndef CONTROLER_H
#define CONTROLER_H

#include "File.h"
#include "Dictionary.h"
#include "Parser.h"
#include <cstring>

using namespace std;

class Controler
{
    public:
        Controler();
        virtual ~Controler();

		void configurate (int argc, char ** argv);
		void run(char* path);

        // Fonctions pour activer les options
        static void enable_o();
        static void enable_a();
        static void enable_p();
        static void enable_e();

    private:
    	// Le fichier
        File* input_file;
        // Le dictionnaire : grammaire
        Dictionary* rules;
        // La parseur de ligne de commande
        Parser* com_parser;
        //
        // Les options
        static bool option_o;
        static bool option_a;
        static bool option_p;
        static bool option_e;

        //Fonctions outil
        void analyse_lexsyn();
        void memload();
        void transformation();      // Option -o
        void affichage();           // Option -p
        void execution();           // Option -e
        void analyse_statique();    // Option -a

};

#endif // CONTROLER_H
