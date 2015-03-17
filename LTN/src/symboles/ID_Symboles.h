#ifndef ID_SYM_H
#define ID_SYM_H

/* Enumeration de tous les symboles de l'automate
 *
 */
enum IdSymbole {
	//---- NON-TERMINAUX ---
	I_P,
		// Declaration
		I_LD,
		I_D,
		// Operations


	//------ TERMINAUX -----
		// General
		I_ID,
		I_NB,
		// Declaration
		I_VAR,
		// Operations

	//Autres (à adapter)
		I_mul, 
		I_pls,
		I_mns,
		I_div,
		I_opA,
		I_opM,
		I_E,
		I_I,
		I_Pprime,
		I_Li,
		I_ptho,
		I_pthf, 
		I_ecrire,
		I_lire,
		I_Idc,
		I_Idv,
		I_nb,
		I_vrg,
		I_egl,
		I_pvrg,
		I_pegl,
		I_const, 
		I_NULL
};


#endif // ID_SYM_H