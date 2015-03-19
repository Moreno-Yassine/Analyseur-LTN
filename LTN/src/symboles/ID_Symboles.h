#ifndef ID_SYM_H
#define ID_SYM_H

/* Enumeration de tous les symboles de l'automate
 *
 */
enum IdSymbole {
	//---- NON-TERMINAUX ---
		I_P,
		I_Pprime,

		// Declaration
		I_LD,
		I_D,
		I_Li,
		I_I,
		I_E,
		I_Idc,
		I_Idv,
		I_mul, 
		I_pls,
		I_mns,
		I_div,
		// Operations
		I_opA,
		I_opM,


	//------ TERMINAUX -----
		// General
		I_ID,
		I_NB,
		I_ecrire,
		I_lire,
		I_ptho,
		I_pthf,
		I_vrg,
		I_egl,
		I_pvrg,
		I_pegl,
		// Declaration
		I_VAR,
		I_const, 
		// Operations

	//Autres (à adapter)		
		I_NULL
};


#endif // ID_SYM_H