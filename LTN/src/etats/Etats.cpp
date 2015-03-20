#include "Etats.h"
#include "../Automate.h"
#include "../symboles/ID_Symboles.h"

/* --------------- ETAT 0 ------------------
 *
 * -----------------------------------------
 */
bool E0::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_P:
			a.decalage(s, new E1);
			break;
		case I_LD:
			a.decalage(s, new E2);
			break;
		case I_const:
			a.reductionEmpile(4, new E2);
			break;
		case I_VAR:
			cout << "VAR Détecté" << endl;
			a.reductionEmpile(4, new E2);
			break;
		case I_ID:
			a.reductionEmpile(4, new E2);
			break;
		case I_lire:
			a.reductionEmpile(4, new E2);
			break;
		case I_ecrire:
			a.reductionEmpile(4, new E2);
			break;
		case I_DOLLAR:
			a.reductionEmpile(4, new E2);
			break;
		default:
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
			//a.decalage(s, new E17); //Non implémenté pour l patie déclarative
			break;
		case I_D:
			a.decalage(s, new E38);
			break;
		default:
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
			a.decalage(s, new E9);
			break;
		default:
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
			a.decalage(s, new E6);
			break;
		default:
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
		default:
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
			break;
	}
	
	return false;
}

E16::~E16()
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
			break;
	}
	
	return false;
}

E39::~E39()
{

}