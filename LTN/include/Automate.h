#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "symboles/Symbole.h"
#include "symboles/SymbolesComplexes.h"
#include "Lexer.h"

#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <typeinfo>

using namespace std;

// Typedef pour la map des variables
typedef std::map<std::string, Declaration*> MapStringDeclaration;
typedef map<std::string, Declaration*>::const_iterator StringDeclarationMapIterator;

//Prédéclaration des classes Etat et Variable (pour l'Edition des Liens)
class Etat;
class Variable;

struct Reduction
{
	int nbElementsADepiler;
	IdSymbole idSymbole;
};

class Automate
{
    public:

		/* Constructeur par Défaut de la Classe Automate
		 * @return : N/A
		 */
        Automate();

		/* Constructeur Personalisé de la Classe Automate
		 * @return : N/A
		 */
		Automate(map<int, string> &Erreurs);

		/* Destructeur de la Classe Automate
		 * @return : N/A
		 */
        virtual ~Automate();

		/* Permet de récupérer la pile des Etats
		 * @return : vector<Etat*>*
		 */
        vector<Etat*>* getPileEtats();

		/* Permet de récupérer la pile des Symboles
		 * @return : vector<Symbole*>*
		 */
		vector<Symbole*>* getPileSymboles();

		/* Permet d'ajouter des Déclaration
		 * @param : 
		 *			name(String) : Nom de la Déclaration ;
		 *			declaration(Declaration*) : Pointeur vers un tableau de Déclarations;
		 * @return : Boolean
		 */
		bool addDeclaration(std::string name, Declaration* declaration);

		/* Permet de définir le flux qu'on a lu à l'aide de la Classe File.h
		 * @param : 
		 *			fileVector(vector<string>) : Pointeur sur ce qu'on a lu dans le fichier en entrée ;
		 * @return : Boolean
		 */
		bool setFile(vector<string> fileVector);

		/* Permet d'empiler le symbole et l'etat dans la pile de l'automate
		 * @param : 
		 *			symbole(Symbole*) : Pointeur sur le symbole qu'on va étudier en vue d'un décalage ou une réduction ;
		 *			etat(Etat*) : Pointeur vers l'état courant pour savoir quelle transition on va effectuer ;
		 * @return : N/A
		 */
		void decalage(Symbole* symbole, Etat* etat);

		/* Permet d'empiler l'état suivant dans la pile de l'automate sans pour autant consommer un symbole
		 * @param : 
		 *			symbole(Symbole*) : Pointeur sur le symbole qu'on va étudier en vue d'un décalage ou une réduction ;
		 *			etat(Etat*) : Pointeur vers l'état courant pour savoir quelle transition on va effectuer ;
		 * @return : N/A
		 */
		void decalageSansConsommation(Etat* etat);

		/* Permet de réduire une règle est d'empiler le symbole et l'etat dans la pile de l'automate
		 * @param : 
		 			numeroRegle (Integer) : Numéro de la règle à utiliser pour réduire ;
		 * @return : N/A
		 */
		void reduction(int numeroRegle);

		/* Permet de construire les règles de réduction qu'on aura à utiliser durant l'execution de l'automate
		 * @param : 
		 *			N/A	
		 * @return : N/A
		 */
		void constructionPileReductions();

		/* Permet de faire l'analyse syntaxique d'une liste de string et de charger sa représentation en memoire
		 * @return : Programme* (La répresentation mémoire du programme)
		 */
		Programme* lecture();

		/* Permet d'afficher le symbole passé en parmètre
		 * @param : 
		 *			symbole(Symbole*) : Pointeur sur le symbole qu'on va afficher;
		 * @return : N/A
		 */
		void affichageEtatAutomate(Symbole* symbole);

		/* Permet d'associer une variable trouvee dans une expression
		 * a une variable precedemment declaree dans le programme
		 * @param : 
		 			currentVar (Variable*) : La variable nouvellement creee trouvee dans E
		 * @return: un pointeur vers la variable du programme declaree
		 *			ou vers la nouvelle variable si celle-ci n'existait pas 
		 *			auparavent (ceci genere un warning)
		 */
		Variable* associerIdVariable(Variable* currentVar);

		/* Permet de récupérer la liste des doublons construite lors de la construction
		 * @param : N/A
		 * @return: le vector contenant le nom de l'ensemble des variables en double
		 */
		vector<string> getListeDoublons() { return listeDoublons; };

		bool isDoublon(string nomVar);

		void setDoublon(string nomVar);




    private:
        MapStringDeclaration tableSymboles;
		vector<string> fluxEntrantP;
        vector<Symbole*>* pileSymboles;
        vector<Etat*>* pileEtats;
        vector<Reduction>* pileReductions;
        Lexer currentLexer;
		Ld* pointeurDeclarations;
		map<int, string> &erreurs;
		int erreurNb;
		vector<string> listeDoublons;
		vector<string> listeVarDeclarees;

};

#endif // AUTOMATE_H
