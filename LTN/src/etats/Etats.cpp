#include "Etats.h"
#include "../Automate.h"
#include "../symboles/ID_Symboles.h"

/* --------------- ETAT 0 ------------------
 *
 * -----------------------------------------
 */
bool E0::transition(Automate &a, Symbole* s)
{
	switch((*s)) {
	case I_P:
		break;
	case I_LD:
		break;
	default:
		break;
	}
	return false;
}