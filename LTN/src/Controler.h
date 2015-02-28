#ifndef CONTROLER_H
#define CONTROLER_H

#include "File.h"
#include "Dictionary.h"
#include "Parser.h"


class Controler
{
    public:
        Controler();
        virtual ~Controler();
		Parser* com_parser; // A privatiser
		void configurate (int argc, char ** argv);

    private:
        File* input_file;
        Dictionary* rules;
        bool configuration [NUM_OPTIONS];

};

#endif // CONTROLER_H
