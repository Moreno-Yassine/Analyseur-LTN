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
		I_VAR , //mot clé
		I_const, //mot clé
		// Operations

	//Autres (à adapter)		
		I_NULL,
		I_DOLLAR
};

/*
std::ostream& operator<<(std::ostream& out, const IdSymbole value){
    static std::map<IdSymbole, std::string> strings;
    if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(I_P);     
        INSERT_ELEMENT(I_Pprime);     
        INSERT_ELEMENT(I_LD);
        INSERT_ELEMENT(I_D); 
        INSERT_ELEMENT(I_Li); 
        INSERT_ELEMENT(I_I); 
        INSERT_ELEMENT(I_E); 
        INSERT_ELEMENT(I_Idc); 
        INSERT_ELEMENT(I_Idv); 
        INSERT_ELEMENT(I_mul); 
        INSERT_ELEMENT(I_pls); 
        INSERT_ELEMENT(I_mns); 
        INSERT_ELEMENT(I_div); 
        INSERT_ELEMENT(I_opA); 
        INSERT_ELEMENT(I_opM); 
        INSERT_ELEMENT(I_ID); 
        INSERT_ELEMENT(I_NB); 
        INSERT_ELEMENT(I_ecrire);              
        INSERT_ELEMENT(I_lire); 
        INSERT_ELEMENT(I_ptho); 
        INSERT_ELEMENT(I_pthf); 
        INSERT_ELEMENT(I_vrg); 
        INSERT_ELEMENT(I_egl); 
        INSERT_ELEMENT(I_pvrg); 
        INSERT_ELEMENT(I_pegl); 
        INSERT_ELEMENT(I_VAR);
        INSERT_ELEMENT(I_const); 
        INSERT_ELEMENT(I_NULL); 
        INSERT_ELEMENT(I_DOLLAR);  
#undef INSERT_ELEMENT
    }   

    return out << strings[value];
}
*/

#endif // ID_SYM_H