#ifndef LEXER_H
#define LEXER_H
#include "symboles/Symbole.h"

class Lexer
{
    public:
        Lexer();
        virtual ~Lexer();
        Symbole getNext();

    private:

};

#endif // LEXER_H
