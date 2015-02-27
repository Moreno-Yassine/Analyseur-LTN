#ifndef CONTROLER_H
#define CONTROLER_H

#include "File.h"
#include "Dictionary.h"

class Controler
{
    public:
        Controler();
        virtual ~Controler();
    protected:
    private:
        File input_file;
        Dictionary rules;
};

#endif // CONTROLER_H
