#include "../../include/etats/Etats.h"
#include "../../include/Automate.h"
#include "../../include/symboles/ID_Symboles.h"

/* --------------- ETAT 0 ------------------
 *
 * -----------------------------------------
 */
bool E0::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_P:
			a.decalageSansConsommation(new E1);
			break;
		case I_LD:
			a.decalageSansConsommation(new E2);
			break;
		case I_const:
			a.reduction(4);
			break;
		case I_VAR:
			a.reduction(4);
			break;
		case I_ID:
			a.reduction(4);
			break;
		case I_lire:
			a.reduction(4);
			break;
		case I_ecrire:
			a.reduction(4);
			break;
		case I_DOLLAR:
			a.reduction(4);
			break;
		default:
			throw 0;
			break;
	}

	return false;
}

E0::~E0()
{

}

/* --------------- ETAT 1 ------------------
 *
 * -----------------------------------------
 */

bool E1::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_DOLLAR:
			return true;
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E1::~E1()
{

}

/* --------------- ETAT 2 ------------------
 *
 * -----------------------------------------
 */
bool E2::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_const:
			a.decalage(s, new E3);
			break;
		case I_VAR:
			a.decalage(s, new E4);
			break;
		case I_ID:
			a.reduction(12);
			break;
		case I_lire:
			a.reduction(12);
			break;
		case I_ecrire:
			a.reduction(12);
			break;
		case I_Li:
			a.decalageSansConsommation(new E17);
			break;
		case I_D:
			a.decalageSansConsommation(new E38);
			break;
		case I_DOLLAR:
			a.decalageSansConsommation(new E17);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E2::~E2()
{

}
/* --------------- ETAT 3 ------------------
 *
 * -----------------------------------------
 */
bool E3::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s, new E14);
			break;
		case I_Idc:
			a.decalageSansConsommation(new E9);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E3::~E3()
{

}
/* --------------- ETAT 4 ------------------
 *
 * -----------------------------------------
 */
bool E4::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s, new E5);
			break;
		case I_Idv:
			a.decalageSansConsommation(new E6);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E4::~E4()
{

}
/* --------------- ETAT 5 ------------------
 *
 * -----------------------------------------
 */
bool E5::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.reduction(10);
			break;
		case I_vrg:
			a.reduction(10);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E5::~E5()
{

}
/* --------------- ETAT 6 ------------------
 *
 * -----------------------------------------
 */
bool E6::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.reduction(6);
			break;
		case I_vrg:
			a.decalage(s, new E7);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E6::~E6()
{

}
/* --------------- ETAT 7 ------------------
 *
 * -----------------------------------------
 */
bool E7::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s, new E8);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E7::~E7()
{

}
/* --------------- ETAT 8 ------------------
 *
 * -----------------------------------------
 */
bool E8::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.reduction(9);
			break;
		case I_vrg:
			a.reduction(9);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E8::~E8()
{

}
/* --------------- ETAT 9 ------------------
 *
 * -----------------------------------------
 */
bool E9::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.reduction(5);
			break;
		case I_vrg:
			a.decalage(s, new E10);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E9::~E9()
{

}
/* --------------- ETAT 10 ------------------
 *
 * -----------------------------------------
 */
bool E10::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s, new E11);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E10::~E10()
{

}
/* --------------- ETAT 11 ------------------
 *
 * -----------------------------------------
 */
bool E11::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_egl:
			a.decalage(s, new E12);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E11::~E11()
{

}
/* --------------- ETAT 12 ------------------
 *
 * -----------------------------------------
 */
bool E12::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_NB:
			a.decalage(s, new E13);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E12::~E12()
{

}
/* --------------- ETAT 13 ------------------
 *
 * -----------------------------------------
 */
bool E13::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.reduction(7);
			break;
		case I_vrg:
			a.reduction(7);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E13::~E13()
{

}
/* --------------- ETAT 14 ------------------
 *
 * -----------------------------------------
 */
bool E14::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_egl:
			a.decalage(s, new E15);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E14::~E14()
{

}
/* --------------- ETAT 15 ------------------
 *
 * -----------------------------------------
 */
bool E15::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_NB:
			a.decalage(s, new E16);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E15::~E15()
{

}
/* --------------- ETAT 16 ------------------
 *
 * -----------------------------------------
 */
bool E16::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.reduction(8);
			break;
		case I_vrg:
			a.reduction(8);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E16::~E16()
{

}

/* --------------- ETAT 17 ------------------
 *
 * -----------------------------------------
 */
bool E17::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s,new E20);
			break;
		case I_lire:
			a.decalage(s,new E18);
			break;
		case I_ecrire:
			a.decalage(s,new E35);
			break;
		case I_DOLLAR:
			if(a.getPileSymboles()->size() == 1)
			{
				a.reduction(12);
			}
			
			a.reduction(2);
			break;
		case I_I:
			a.decalageSansConsommation(new E40);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E17::~E17()
{

}

/* --------------- ETAT 18 ------------------
 *
 * -----------------------------------------
 */
bool E18::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s,new E19);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E18::~E18()
{

}

/* --------------- ETAT 19 ------------------
 *
 * -----------------------------------------
 */
bool E19::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.reduction(13);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E19::~E19()
{

}

/* --------------- ETAT 20 ------------------
 *
 * -----------------------------------------
 */
bool E20::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pegl:
			a.decalage(s,new E21);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E20::~E20()
{

}

/* --------------- ETAT 21 ------------------
 *
 * -----------------------------------------
 */
bool E21::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s,new E23);
			break;
		case I_NB:
			a.decalage(s,new E22);
			break;
		case I_ptho:
			a.decalage(s,new E24);
			break;
		case I_E:
			a.decalageSansConsommation(new E27);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E21::~E21()
{

}


/* --------------- ETAT 22 ------------------
 * 
 * -----------------------------------------
 */
bool E22::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reduction(17);
			break;
		case I_mul:
			a.reduction(17);
			break;
		case I_mns:
			a.reduction(17);
			break;
		case I_pvrg:
			a.reduction(17);
			break;
		case I_div:
			a.reduction(17);
			break;
		case I_pthf:
			a.reduction(17);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E22::~E22()
{

}

/* --------------- ETAT 23 ------------------
 * 
 * -----------------------------------------
 */ 
bool E23::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reduction(16);
			break;
		case I_mul:
			a.reduction(16);
			break;
		case I_mns:
			a.reduction(16);
			break;
		case I_pvrg:
			a.reduction(16);
			break;
		case I_div:
			a.reduction(16);
			break;
		case I_pthf:
			a.reduction(16);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E23::~E23()
{

}


/* --------------- ETAT 24 ------------------
 *
 * -----------------------------------------
 */
bool E24::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s,new E23);
			break;
		case I_NB:
			a.decalage(s,new E22);
			break;
		case I_ptho:
			a.decalage(s,new E24);
			break;
		case I_E:
			a.decalageSansConsommation(new E25);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E24::~E24()
{

}


/* --------------- ETAT 25 ------------------
 *
 * -----------------------------------------
 */
bool E25::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.decalage(s,new E31);
			break;
		case I_mul:
			a.decalage(s,new E29);
			break;
		case I_mns:
			a.decalage(s,new E30);
			break;
		case I_div:
			a.decalage(s,new E28);
			break;
		case I_pthf:
			a.decalage(s,new E26);
			break;
		case I_opA:
			a.decalageSansConsommation(new E32);
			break;
		case I_opM:
			a.decalageSansConsommation(new E33);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E25::~E25()
{

}

/* --------------- ETAT 26 ------------------
 * 
 * -----------------------------------------
 */
bool E26::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reduction(20);
			break;
		case I_mul:
			a.reduction(20);
			break;
		case I_mns:
			a.reduction(20);
			break;
		case I_pvrg:
			a.reduction(20);
			break;
		case I_div:
			a.reduction(20);
			break;
		case I_pthf:
			a.reduction(20);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E26::~E26()
{

}


/* --------------- ETAT 27 ------------------
 *
 * -----------------------------------------
 */
bool E27::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.decalage(s,new E31);
			break;
		case I_mul:
			a.decalage(s,new E29);
			break;
		case I_mns:
			a.decalage(s,new E30);
			break;
		case I_div:
			a.decalage(s,new E28);
			break;
		case I_pvrg:
			a.reduction(15);
			break;
		case I_opA:
			a.decalageSansConsommation(new E32);
			break;
		case I_opM:
			a.decalageSansConsommation(new E33);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E27::~E27()
{

}

/* --------------- ETAT 28 ------------------
 *
 * -----------------------------------------
 */
bool E28::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.reduction(23);
			break;
		case I_NB:
			a.reduction(23);
			break;
		case I_ptho:
			a.reduction(23);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E28::~E28()
{

}

/* --------------- ETAT 29 ------------------
 *
 * -----------------------------------------
 */
bool E29::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.reduction(24);
			break;
		case I_NB:
			a.reduction(24);
			break;
		case I_ptho:
			a.reduction(24);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E29::~E29()
{

}

/* --------------- ETAT 30 ------------------
 *
 * -----------------------------------------
 */
bool E30::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.reduction(22);
			break;
		case I_NB:
			a.reduction(22);
			break;
		case I_ptho:
			a.reduction(22);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E30::~E30()
{

}

/* --------------- ETAT 31 ------------------
 *
 * -----------------------------------------
 */
bool E31::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.reduction(21);
			break;
		case I_NB:
			a.reduction(21);
			break;
		case I_ptho:
			a.reduction(21);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E31::~E31()
{

}

/* --------------- ETAT 32 ------------------
 *
 * -----------------------------------------
 */
bool E32::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s,new E23);
			break;
		case I_NB:
			a.decalage(s,new E22);
			break;
		case I_E:
			a.decalageSansConsommation(new E34);
			break;
		case I_ptho:
			a.decalage(s,new E24);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E32::~E32()
{

}

/* --------------- ETAT 33 ------------------
 *
 * -----------------------------------------
 */
bool E33::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s,new E23);
			break;
		case I_NB:
			a.decalage(s,new E22);
			break;
		case I_E:
			a.decalageSansConsommation(new E37);
			break;
		case I_ptho:
			a.decalage(s,new E24);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E33::~E33()
{

}


/* --------------- ETAT 34 ------------------
 *
 * -----------------------------------------
 */
bool E34::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reduction(18);
			break;
		case I_mul:
			a.decalage(s,new E29);
			break;
		case I_mns:
			a.reduction(18);
			break;
		case I_div:
			a.decalage(s,new E28);
			break;
		case I_pthf:
			a.reduction(18);
			break;
		case I_pvrg:
			a.reduction(18);
			break;
		case I_opA:
			a.decalageSansConsommation(new E32);
			break;
		case I_opM:
			a.decalageSansConsommation(new E33);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E34::~E34()
{

}


/* --------------- ETAT 35 ------------------
 *
 * -----------------------------------------
 */
bool E35::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.decalage(s,new E23);
			break;
		case I_NB:
			a.decalage(s,new E22);
			break;
		case I_E:
			a.decalageSansConsommation(new E36);
			break;
		case I_ptho:
			a.decalage(s, new E24);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E35::~E35()
{

}

/* --------------- ETAT 36 ------------------
 *
 * -----------------------------------------
 */
bool E36::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.decalage(s,new E31);
			break;
		case I_mul:
			a.decalage(s,new E29);
			break;
		case I_mns:
			a.decalage(s,new E30);
			break;
		case I_div:
			a.decalage(s,new E28);
			break;
		case I_pvrg:
			a.reduction(14);
			break;
		case I_opA:
			a.decalageSansConsommation(new E32);
			break;
		case I_opM:
			a.decalageSansConsommation(new E33);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E36::~E36()
{

}

/* --------------- ETAT 37 ------------------
 * 
 * -----------------------------------------
 */
bool E37::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reduction(19);
			break;
		case I_mul:
			a.reduction(19);
			break;
		case I_mns:
			a.reduction(19);
			break;
		case I_div:
			a.reduction(19);
			break;
		case I_pvrg:
			a.reduction(19);
			break;
		case I_pthf:
			a.reduction(19);
			break;
		case I_opA:
			a.decalageSansConsommation(new E32);
			break;
		case I_opM:
			a.decalageSansConsommation(new E33);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E37::~E37()
{

}


/* --------------- ETAT 38 ------------------
 *
 * -----------------------------------------
 */
bool E38::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.decalage(s, new E39);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E38::~E38()
{

}
/* --------------- ETAT 39 ------------------
 *
 * -----------------------------------------
 */
bool E39::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_const:
			a.reduction(3);
			break;
		case I_VAR:
			a.reduction(3);
			break;
		case I_ID:
			a.reduction(3);
			break;
		case I_lire:
			a.reduction(3);
			break;
		case I_ecrire:
			a.reduction(3);
			break;
		case I_DOLLAR:
			a.reduction(3);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E39::~E39()
{

}


/* --------------- ETAT 40 ------------------
 *
 * -----------------------------------------
 */
bool E40::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_pvrg:
			a.decalage(s,new E41);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E40::~E40()
{

}

/* --------------- ETAT 41 ------------------
 *
 * -----------------------------------------
 */
bool E41::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.reduction(11);
			break;
		case I_lire:
			a.reduction(11);
			break;
		case I_ecrire:
			a.reduction(11);
			break;
		case I_DOLLAR:
			a.reduction(11);
			break;
		default:
			throw 0;
			break;
	}
	
	return false;
}

E41::~E41()
{

}
