#ifndef EGL_H
#define EGL_H

#include "../Symbole.h"
#include <string>

class Egl : public Symbole
{
    public:
        Egl();
        virtual ~Egl();

    private:
    	string mot;

};

#endif // EGL_H