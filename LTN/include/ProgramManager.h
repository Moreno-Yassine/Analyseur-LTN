#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include "symboles/Symbole.h"
#include "symboles/SymbolesComplexes.h"
#include <map>
#include <vector>

class ProgramManager
{
    public:
        /* Constructeur par Défaut de la Classe ProgramManager
         * @return : N/A
         */
        ProgramManager();

     	 /* Destructeur de la Classe ProgramManager
         * @return : N/A
         */
        virtual ~ProgramManager();

        /*	Permet d'initialiser l'attribut privé program de la classe
         * @param :
		 			programme (Programme*) : Le programme renvoyé par l'automate
         * @return : N/A
		 */
        void setProgram(Programme* programme);

        /*	Permet de lancer l'execution du programme
         * @return : N/A
		 */
        void execute();

        /*	Permet d'afficher le programme
         * @return : N/A
		 */
        void displayProgram();

        /*	Permet de lancer l'optimisation du programme
         * @return : N/A
		 */
        void optimise();

        /*	Permet de lancer l'analyse statique du programme
         * @param :
                    erreurs (map<int,string>&) : reference vers la structure contenant les erreurs
                    détectées en phase de répresentation mémoire
         * @return : N/A
		 */
        void analyseStatique(map<int,string> &erreurs);

        /*	Permet d'afficher les variables pas déclarées du programme
         * @param :
                    erreurs (map<int,string>&) : reference vers la structure contenant les erreurs
                    détectées en phase de répresentation mémoire
         * @return : N/A
		 */
        void afficheVariablesPasDecl(map<int, string> &erreurs);
		void setDoublons(vector<string> listeDoublons) {doublons = listeDoublons;};


    private:
        Programme* program;
		vector<string> doublons;
};

#endif // PROGRAMMANAGER_H
