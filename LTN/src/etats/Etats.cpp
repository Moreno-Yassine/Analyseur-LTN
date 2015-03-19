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
			break;
	}

	return false;
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