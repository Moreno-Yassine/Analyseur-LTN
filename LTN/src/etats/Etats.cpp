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
			a.reductionEmpile(12, new E17);
			break;
		case I_lire:
			a.reductionEmpile(12, new E17);
			break;
		case I_ecrire:
			a.reductionEmpile(12, new E17);
			break;
		case I_Li:
			a.decalage(s, new E17);
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
			a.reductionEmpile(10, new E6);
			break;
		case I_vrg:
			a.reductionEmpile(10, new E6);
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
			a.reductionEmpile(6, new E38);
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
			a.reductionEmpile(9, new E6);
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
			a.reductionEmpile(5, new E38);
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
			a.reductionEmpile(7, new E9);
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
	cout << "Symbole ID = " << s->toString() << endl;
	IdSymbole id = I_pvrg;
	cout << "Testeur = " << I_egl << endl;
	cout << "Testé = " << s->getIdSymbole() << endl;
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
			a.reductionEmpile(8, new E9);
			break;
		case I_vrg:
			a.reductionEmpile(8, new E9);
			break;
		default:
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
			a.reductionEmpile(2,new E1);
			break;
		case I_I:
			a.decalage(s,new E40);
			break;
		default:
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
		/* Erreur dans la Table à élimiter
		case I_E:
			a.decalage(s,new E19);
			break;*/
		default:
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
			a.reductionEmpile(13,new E40);
			break;
		default:
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
			a.decalage(s,new E21);
			break;
		case I_NB:
			a.decalage(s,new E22);
			break;
		case I_ptho:
			a.decalage(s,new E24);
			break;
		case I_E:
			a.decalage(s,new E27);
			break;
		default:
			break;
	}
	
	return false;
}

E21::~E21()
{

}


/* --------------- ETAT 22 ------------------
 * La réduction est ambigue car elle dépend si on vient de l'Etat 21, 24, 32, 33 ou 35
 * -----------------------------------------
 */
bool E22::transition(Automate &a, Symbole* s)
{
	Etat* etatSuivant;
	Etat* etatPrecedent = a.getPileEtats()->at(a.getPileEtats()->size() - 2); //A Améliorer

	//On récupère l'Etat Précèdent empilé pour savoir l'Etat Suivant à choisir
	if(etatPrecedent->getNomEtat().compare("E21") == 0)
	{
		etatSuivant = new E27;
	}
	else if(etatPrecedent->getNomEtat().compare("E24") == 0)
	{
		etatSuivant = new E25;
	}
	else if(etatPrecedent->getNomEtat().compare("E32") == 0)
	{
		etatSuivant = new E34;
	}
	else if(etatPrecedent->getNomEtat().compare("E33") == 0)
	{
		etatSuivant = new E37;
	}
	else if(etatPrecedent->getNomEtat().compare("E35") == 0)
	{
		etatSuivant = new E36;
	}
	else
	{
		cout << "Pas d'Etat Suivant trouvé pour E22" << endl;
	}

	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reductionEmpile(17, etatSuivant);
			break;
		case I_mul:
			a.reductionEmpile(17, etatSuivant);
			break;
		case I_mns:
			a.reductionEmpile(17, etatSuivant);
			break;
		case I_pvrg:
			a.reductionEmpile(17, etatSuivant);
			break;
		case I_div:
			a.reductionEmpile(17, etatSuivant);
			break;
		case I_pthf:
			a.reductionEmpile(17, etatSuivant);
			break;
		default:
			break;
	}
	
	return false;
}

E22::~E22()
{

}

/* --------------- ETAT 23 ------------------
 * La réduction est ambigue car elle dépend si on vient de l'Etat 21, 24, 32, 33 ou 35
 * -----------------------------------------
 */ 
bool E23::transition(Automate &a, Symbole* s)
{
	Etat* etatSuivant;
	Etat* etatPrecedent = a.getPileEtats()->at(a.getPileEtats()->size() - 2); //A Améliorer

	//On récupère l'Etat Précèdent empilé pour savoir l'Etat Suivant à choisir
	if(etatPrecedent->getNomEtat().compare("E21") == 0)
	{
		etatSuivant = new E27;
	}
	else if(etatPrecedent->getNomEtat().compare("E24") == 0)
	{
		etatSuivant = new E25;
	}
	else if(etatPrecedent->getNomEtat().compare("E32") == 0)
	{
		etatSuivant = new E34;
	}
	else if(etatPrecedent->getNomEtat().compare("E33") == 0)
	{
		etatSuivant = new E37;
	}
	else if(etatPrecedent->getNomEtat().compare("E35") == 0)
	{
		etatSuivant = new E36;
	}
	else
	{
		cout << "Pas d'Etat Suivant trouvé pour E23" << endl;
	}

	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reductionEmpile(16, etatSuivant);
			break;
		case I_mul:
			a.reductionEmpile(16, etatSuivant);
			break;
		case I_mns:
			a.reductionEmpile(16, etatSuivant);
			break;
		case I_pvrg:
			a.reductionEmpile(16, etatSuivant);
			break;
		case I_div:
			a.reductionEmpile(16, etatSuivant);
			break;
		case I_pthf:
			a.reductionEmpile(16, etatSuivant);
			break;
		default:
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
			a.decalage(s,new E25);
			break;
		default:
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
		default:
			break;
	}
	
	return false;
}

E25::~E25()
{

}

/* --------------- ETAT 26 ------------------
 * La réduction est ambigue car elle dépend si on vient de l'Etat 21, 32, 33 ou 55
 * -----------------------------------------
 */
bool E26::transition(Automate &a, Symbole* s)
{
	Etat* etatSuivant;
	Etat* etatPrecedentTroisPositionsAvant = a.getPileEtats()->at(a.getPileEtats()->size() - 4); //A Améliorer
	//On récupère l'Etat Précèdent empilé pour savoir l'Etat Suivant à choisir
	if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E21") == 0)
	{
		etatSuivant = new E27;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E32") == 0)
	{
		etatSuivant = new E34;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E33") == 0)
	{
		etatSuivant = new E37;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E35") == 0)
	{
		etatSuivant = new E36;
	}
	else
	{
		cout << "Pas d'Etat Suivant trouvé pour E26" << endl;
	}


	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reductionEmpile(20, etatSuivant);
			break;
		case I_mul:
			a.reductionEmpile(20, etatSuivant);
			break;
		case I_mns:
			a.reductionEmpile(20, etatSuivant);
			break;
		case I_pvrg:
			a.reductionEmpile(20, etatSuivant);
			break;
		case I_div:
			a.reductionEmpile(20, etatSuivant);
			break;
		case I_pthf:
			a.reductionEmpile(20, etatSuivant);
			break;
		default:
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
			a.reductionEmpile(15,new E40);
			break;
		case I_opA:
			a.decalage(s,new E32);
			break;
		case I_opM:
			a.decalage(s,new E33);
			break;
		default:
			break;
	}
	
	return false;
}

E27::~E27()
{

}

/* --------------- ETAT 28 ------------------
 *La réduction est ambigue car elle dépend si on vient de l'Etat 25, 27, 34, 36 ou 37
 * -----------------------------------------
 */
bool E28::transition(Automate &a, Symbole* s)
{
	switch(s->getIdSymbole())
	 {
		case I_ID:
			a.reductionEmpile(23,new E33);		//A VERIFIER !!!!!
			break;
		case I_NB:
			a.reductionEmpile(23,new E33);
			break;
		case I_ptho:
			a.reductionEmpile(23,new E33);
			break;
		default:
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
			a.reductionEmpile(24,new E33);
			break;
		case I_NB:
			a.reductionEmpile(24,new E33);
			break;
		case I_ptho:
			a.reductionEmpile(24,new E33);
			break;
		default:
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
			a.reductionEmpile(22,new E32);
			break;
		case I_NB:
			a.reductionEmpile(22,new E32);
			break;
		case I_ptho:
			a.reductionEmpile(22,new E32);
			break;
		default:
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
			a.reductionEmpile(21,new E32);
			break;
		case I_NB:
			a.reductionEmpile(21,new E32);
			break;
		case I_ptho:
			a.reductionEmpile(21,new E32);
			break;
		default:
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
			a.decalage(s,new E34);
			break;
		case I_ptho:
			a.decalage(s,new E24);
			break;
		default:
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
			a.decalage(s,new E37);
			break;
		case I_ptho:
			a.decalage(s,new E24);
			break;
		default:
			break;
	}
	
	return false;
}

E33::~E33()
{

}


/* --------------- ETAT 34 ------------------
 *La réduction est ambigue car elle dépend si on vient de l'Etat 21, 24, 32, 35
 * -----------------------------------------
 */
bool E34::transition(Automate &a, Symbole* s)
{
	Etat* etatSuivant;
	Etat* etatPrecedentTroisPositionsAvant = a.getPileEtats()->at(a.getPileEtats()->size() - 4); //A Améliorer

	//On récupère l'Etat Précèdent empilé pour savoir l'Etat Suivant à choisir
	if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E21") == 0)
	{
		etatSuivant = new E27;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E24") == 0)
	{
		etatSuivant = new E25;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E32") == 0)
	{
		etatSuivant = new E34;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E35") == 0)
	{
		etatSuivant = new E36;
	}
	else
	{
		cout << "Pas d'Etat Suivant trouvé pour E34" << endl;
	}

	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reductionEmpile(18, etatSuivant);
		case I_mul:
			a.decalage(s,new E29);
		case I_mns:
			a.reductionEmpile(18, etatSuivant);
		case I_div:
			a.decalage(s,new E28);
		case I_pthf:
			a.reductionEmpile(18, etatSuivant);
		case I_pvrg:
			a.reductionEmpile(18, etatSuivant);
		case I_opA:
			a.decalage(s,new E32);
		case I_opM:
			a.decalage(s,new E33);
		default:
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
			a.decalage(s,new E36);
			break;
		default:
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
		case I_mul:
			a.decalage(s,new E29);
		case I_mns:
			a.decalage(s,new E30);
		case I_div:
			a.decalage(s,new E28);
		case I_pvrg:
			a.reductionEmpile(14,new E40);

		case I_opA:
			a.decalage(s,new E32);
		case I_opM:
			a.decalage(s,new E33);
		default:
			break;
	}
	
	return false;
}

E36::~E36()
{

}

/* --------------- ETAT 37 ------------------
 * La réduction est ambigue car elle dépend si on vient de l'Etat 21, 24, 32, 35
 * -----------------------------------------
 */
bool E37::transition(Automate &a, Symbole* s)
{
	Etat* etatSuivant;
	Etat* etatPrecedentTroisPositionsAvant = a.getPileEtats()->at(a.getPileEtats()->size() - 4); //A Améliorer
	//On récupère l'Etat Précèdent empilé pour savoir l'Etat Suivant à choisir
	if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E21") == 0)
	{
		etatSuivant = new E27;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E24") == 0)
	{
		etatSuivant = new E25;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E33") == 0)
	{
		etatSuivant = new E37;
	}
	else if(etatPrecedentTroisPositionsAvant->getNomEtat().compare("E35") == 0)
	{
		etatSuivant = new E36;
	}
	else
	{
		cout << "Pas d'Etat Suivant trouvé pour E37" << endl;
	}

	switch(s->getIdSymbole())
	 {
		case I_pls:
			a.reductionEmpile(19, etatSuivant);
		case I_mul:
			a.reductionEmpile(19, etatSuivant);
		case I_mns:
			a.reductionEmpile(19, etatSuivant);
		case I_div:
			a.reductionEmpile(19, etatSuivant);
		case I_pvrg:
			a.reductionEmpile(19, etatSuivant);
		case I_pthf:
			a.reductionEmpile(19, etatSuivant);
		case I_opA:
			a.decalage(s,new E32);
		case I_opM:
			a.decalage(s,new E33);
		default:
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
			a.reductionEmpile(3, new E2);
			break;
		case I_VAR:
			a.reductionEmpile(3, new E2);
			break;
		case I_ID:
			a.reductionEmpile(3, new E2);
			break;
		case I_lire:
			a.reductionEmpile(3, new E2);
			break;
		case I_ecrire:
			a.reductionEmpile(3, new E2);
			break;
		case I_DOLLAR:
			a.reductionEmpile(3, new E2);
			break;
		default:
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
		default:
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
			a.reductionEmpile(11, new E17);
			break;
		case I_lire:
			a.reductionEmpile(11, new E17);
			break;
		case I_ecrire:
			a.reductionEmpile(11, new E17);
			break;
		case I_DOLLAR:
			a.reductionEmpile(11, new E17);		//A VERIFIER !!!!!!!!!!!
			break;
		default:
			break;
	}
	
	return false;
}

E41::~E41()
{

}