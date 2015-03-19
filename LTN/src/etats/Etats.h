#ifndef ETATS_H
#define ETATS_H

#include <iostream>
#include "Etat.h"
//#include "../Automate.h"
#include "../symboles/Programme.h"
#include "../symboles/Ld.h"

using namespace std;
class Automate;
/* ------- Etat 0  --------
 * 
 * ------------------------
 */
class E0 : public Etat
{
    public:
		E0():Etat("E0"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E0();

    private:
        std::string nom;

};

class E1 : public Etat
{
    public:
		E1():Etat("E1"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E1();

    private:
        std::string nom;

};

class E2 : public Etat
{
    public:
		E2():Etat("E2"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E2();

    private:
        std::string nom;

};

class E3 : public Etat
{
    public:
		E3():Etat("E3"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E3();

    private:
        std::string nom;

};

class E4 : public Etat
{
    public:
		E4():Etat("E4"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E4();

    private:
        std::string nom;

};

class E5 : public Etat
{
    public:
		E5():Etat("E5"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E5();

    private:
        std::string nom;

};

class E6 : public Etat
{
    public:
		E6():Etat("E6"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E6();

    private:
        std::string nom;

};

class E7 : public Etat
{
    public:
		E7():Etat("E7"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E7();

    private:
        std::string nom;

};

class E8 : public Etat
{
    public:
		E8():Etat("E8"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E8();

    private:
        std::string nom;

};

class E9 : public Etat
{
    public:
		E9():Etat("E9"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E9();

    private:
        std::string nom;

};

class E10 : public Etat
{
    public:
		E10():Etat("E10"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E10();

    private:
        std::string nom;

};

class E11 : public Etat
{
    public:
		E11():Etat("E11"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E11();

    private:
        std::string nom;

};

class E12 : public Etat
{
    public:
		E12():Etat("E12"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E12();

    private:
        std::string nom;

};

class E13 : public Etat
{
    public:
		E13():Etat("E13"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E13();

    private:
        std::string nom;

};

class E14 : public Etat
{
    public:
		E14():Etat("E14"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E14();

    private:
        std::string nom;

};

class E15 : public Etat
{
    public:
		E15():Etat("E15"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E15();

    private:
        std::string nom;

};

class E16 : public Etat
{
    public:
		E16():Etat("E16"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E16();

    private:
        std::string nom;

};

class E38 : public Etat
{
    public:
		E38():Etat("E38"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E38();

    private:
        std::string nom;

};

class E39 : public Etat
{
    public:
		E39():Etat("E39"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E39();

    private:
        std::string nom;

};

#endif // ETATS_H
