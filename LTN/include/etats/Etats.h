#ifndef ETATS_H
#define ETATS_H

#include <iostream>
#include "Etat.h"
#include "../symboles/SymbolesComplexes.h"

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

class E17 : public Etat
{
    public:
		E17():Etat("E17"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E17();

    private:
        std::string nom;

};

class E18 : public Etat
{
    public:
		E18():Etat("E18"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E18();

    private:
        std::string nom;

};

class E19 : public Etat
{
    public:
		E19():Etat("E19"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E19();

    private:
        std::string nom;

};


class E20 : public Etat
{
    public:
		E20():Etat("E20"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E20();

    private:
        std::string nom;

};

class E21 : public Etat
{
    public:
		E21():Etat("E21"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E21();

    private:
        std::string nom;

};

class E22 : public Etat
{
    public:
		E22():Etat("E22"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E22();

    private:
        std::string nom;

};

class E23 : public Etat
{
    public:
		E23():Etat("E23"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E23();

    private:
        std::string nom;

};

class E24 : public Etat
{
    public:
		E24():Etat("E24"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E24();

    private:
        std::string nom;

};

class E25 : public Etat
{
    public:
		E25():Etat("E25"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E25();

    private:
        std::string nom;

};

class E26 : public Etat
{
    public:
		E26():Etat("E26"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E26();

    private:
        std::string nom;

};

class E27 : public Etat
{
    public:
		E27():Etat("E27"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E27();

    private:
        std::string nom;

};

class E28 : public Etat
{
    public:
		E28():Etat("E28"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E28();

    private:
        std::string nom;

};

class E29 : public Etat
{
    public:
		E29():Etat("E29"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E29();

    private:
        std::string nom;

};

class E30 : public Etat
{
    public:
		E30():Etat("E30"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E30();

    private:
        std::string nom;

};

class E31 : public Etat
{
    public:
		E31():Etat("E31"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E31();

    private:
        std::string nom;

};

class E32 : public Etat
{
    public:
		E32():Etat("E32"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E32();

    private:
        std::string nom;

};

class E33 : public Etat
{
    public:
		E33():Etat("E33"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E33();

    private:
        std::string nom;

};

class E34 : public Etat
{
    public:
		E34():Etat("E34"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E34();

    private:
        std::string nom;

};

class E35 : public Etat
{
    public:
		E35():Etat("E35"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E35();

    private:
        std::string nom;

};

class E36 : public Etat
{
    public:
		E36():Etat("E36"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E36();

    private:
        std::string nom;

};

class E37 : public Etat
{
    public:
		E37():Etat("E37"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E37();

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

class E40 : public Etat
{
    public:
		E40():Etat("E40"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E40();

    private:
        std::string nom;

};

class E41 : public Etat
{
    public:
		E41():Etat("E41"){};
		bool transition(Automate &automate, Symbole* symbole);
        virtual ~E41();

    private:
        std::string nom;

};

#endif // ETATS_H
