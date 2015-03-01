#ifndef CONTROLER_H
#define CONTROLER_H

#include "File.h"
#include "Dictionary.h"
#include "Parser.h"

using namespace std;

class Controler
{
    public:
        Controler();
        virtual ~Controler();

		void configurate (int argc, char ** argv);

    private:
        File* input_file;
        Dictionary* rules;
        Parser* com_parser;
        bool* configuration;

};

#endif // CONTROLER_H
