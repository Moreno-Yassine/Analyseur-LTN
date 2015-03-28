#include "../include/Automate.h"
#include "../include/etats/Etat.h"
#include "../include/etats/Etats.h"
#include "../include/symboles/Variable.h"
#include "../include/symboles/Valeur.h"

Automate::Automate()
{
    pileSymboles = new vector<Symbole*>();
    pileEtats = new vector<Etat*>();
    pileReductions = new vector<Reduction>();
    currentLexer = Lexer();
    this->constructionPileReductions();
	pointeurDeclarations = NULL;
}

Automate::~Automate()
{

}

vector<Etat*>* Automate::getPileEtats()
{
    return pileEtats;
}

vector<Symbole*>* Automate::getPileSymboles()
{
    return pileSymboles;
}

// Add declaration
bool Automate::addDeclaration(std::string name, Declaration* declaration)
{
    return (tableSymboles.insert(std::pair<std::string, Declaration*>(name, declaration))).second;
}

void Automate::decalage(Symbole* symbole, Etat* etat)
{

	pileSymboles->push_back(symbole);
	pileEtats->push_back(etat);
    currentLexer.shift();
}

void Automate::decalageSansConsommation(Etat* etat)
{
    pileEtats->push_back(etat);
}

void Automate::reduction(int numeroRegle)
{
    Symbole* symbole = NULL;
    IdSymbole idSymbole;
    int nombreADepiler;
    if(numeroRegle > 0 && numeroRegle <= (int)pileReductions->size())
    {
        nombreADepiler = (pileReductions->at(numeroRegle - 1)).nbElementsADepiler;
        idSymbole = (pileReductions->at(numeroRegle - 1)).idSymbole;

        switch(idSymbole)
        {
            case I_Pprime : symbole = NULL; break;
            case I_P :
            	//cout << "Je crée le programme" << endl;
				symbole = new Programme();
				symbole->setParam(pileSymboles->at(pileSymboles->size() - 2), 1);
				symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 2);
				/*cout << pileSymboles->at(pileSymboles->size() - 2)->getIdSymbole() << endl;
				cout << pileSymboles->at(pileSymboles->size() - 1)->getIdSymbole() << endl;
				cout << "Création terminée" << endl;*/
				break;
            case I_LD : 
				switch(numeroRegle)
				{
					case 3:					
						pileSymboles->at(pileSymboles->size() - 3)->setParam(pileSymboles->at(pileSymboles->size() - 2), 2);
						symbole = pileSymboles->at(pileSymboles->size() - 3);
						//La liste de declaration est le symbole courant
						pointeurDeclarations = (Ld*)symbole;
					   break;
					case 4:
						symbole = new Ld(); 
						break;
					default:
						break;
				}		
				break;
            case I_D :
				switch(numeroRegle)
				{
					case 5:
						symbole = new DeclListCons();
						symbole->setId(I_D,"I_D");
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					case 6:
						symbole = new DeclListVar();
						symbole->setId(I_D,"I_D");
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					default:
						break;
				}
				break;
            case I_Idc : 
				switch(numeroRegle)
				{
					case 7:						
						pileSymboles->at(pileSymboles->size() - 5)->setParam(pileSymboles->at(pileSymboles->size() - 3), 1);
						pileSymboles->at(pileSymboles->size() - 5)->setParam(pileSymboles->at(pileSymboles->size() - 1), 2);
						symbole = pileSymboles->at(pileSymboles->size() - 5);
						break;
					case 8:
						symbole = new Idc(); 
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 3), 1);
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 2);
						break;
					default:
						break;
				}
                break;						
           case I_Idv : 
				switch(numeroRegle)
				{
					case 9:												
						pileSymboles->at(pileSymboles->size() - 3)->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						symbole = pileSymboles->at(pileSymboles->size() - 3);
						break;
					case 10:
						symbole = new Idv(); 
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					default:
						break;
				}
                break;	
            case I_E :
				switch(numeroRegle)
				{
					case 16:
						//Modification Damien
						/* ancien code
						symbole = new Variable();
						symbole->setId(I_E,"I_E");
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						*/
						//On reduit un id, donc le dernier element de la pile est une variable
						// On recupere la variable associee, qui est notre nouvelle variable
						// donc notre nouveau symbole
						symbole = associerIdVariable((Variable*)pileSymboles->at(pileSymboles->size()-1));
						//On change bien l'Id du symbole de la declaration (lié à IdV ou IdC)
						//mais comme il ne passera plus dans l'automate (à part dans notre cas)
						//ce n'est pas grave
						symbole->setId(I_E,"I_E");
						break;
					case 17:
						symbole = new Valeur();
						symbole->setId(I_E,"I_E");
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					case 18:
						symbole = new EPlus();
						symbole->setId(I_E,"I_E");
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 3), 1);
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 2), 2);
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 3);					
						break;
					case 19:
						symbole = new EMult();
						symbole->setId(I_E,"I_E");
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 3), 1);
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 2), 2);
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 3);
						break;
					case 20:
						symbole = new EParantheses();
						symbole->setId(I_E,"I_E");
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 2), 1);
						break;
					default:
						break;
				}
				break;
            case I_Li : 
				switch(numeroRegle)
				{
                    //A VERIFIER => Ludmila tu dois valider mais c'est bon normalement (signé Julien)
					case 11:
						pileSymboles->at(pileSymboles->size() - 3)->setParam(pileSymboles->at(pileSymboles->size() - 2), 2);
						symbole = pileSymboles->at(pileSymboles->size() - 3);
						break;
					case 12:
						symbole = new Li();
						break;
					default:
						break;
				}
				break;
            case I_I :
				Variable* ptVarReelle;
				switch(numeroRegle)
				{
					case 13:
						//Modif Damien
						ptVarReelle = associerIdVariable((Variable*)pileSymboles->at(pileSymboles->size()-1));
						symbole = new LectureInstr();
						symbole->setId(I_I,"I_I");
						symbole->setParam(ptVarReelle, 1);
						break;
					case 14:
						symbole = new EcritureInstr();
						symbole->setId(I_I,"I_I");
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					case 15:
						//Modif Damien
						ptVarReelle = associerIdVariable((Variable*)pileSymboles->at(pileSymboles->size()-3));
						symbole = new AffectationInstr();
						symbole->setId(I_I,"I_I");
						symbole->setParam(ptVarReelle, 1);
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 2);
						break;
					default:
						break;
				}
				break;
            case I_opA :
				switch(numeroRegle)
				{
					case 21: 
						symbole = new opA();
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					case 22: 
						symbole = new opA();
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					default:
						break;
				}
				break;
            case I_opM : 
				switch(numeroRegle)
				{
					case 23: 
						symbole = new opM(); 
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					case 24: 
						symbole = new opM(); 
						symbole->setParam(pileSymboles->at(pileSymboles->size() - 1), 1);
						break;
					default:
						break;
				}
				break;
	
            default : symbole = NULL; break;
        }       


        if(symbole != NULL)
        {
            //Création du nouveau symbole avec les ancians symboles
            for(int i=nombreADepiler; i>0; i--)
            {
                symbole->ajoutSymbole(pileSymboles->at(pileSymboles->size() - i));
            }

            //Nettoyage des pileSymboles et pileEtats en supprimant nombreADepiler Elements
            for(int i=0; i<nombreADepiler; i++)
            {
                pileSymboles->pop_back();
                pileEtats->pop_back();
            }

            //Ajout du nouveau symbole dans la pileSymboles
            pileSymboles->push_back(symbole);

            //On fait la transition sans consommation (correspond à un décalage sans consommation)
            pileEtats->back()->transition(*this, pileSymboles->back());
        }
    }
    else
    {
        nombreADepiler = 0;
        idSymbole = I_NULL;
    }
}

void Automate::constructionPileReductions()
{
    pileReductions->clear();
	
    Reduction reduction;

    //Pour R1 : P' -> P
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Pprime;
    pileReductions->push_back(reduction);

    //Pour R2 : P -> Ld Li
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_P;
    pileReductions->push_back(reduction);

    //Pour R3 : Ld -> Ld D ;
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_LD;
    pileReductions->push_back(reduction);

    //Pour R4 : Ld -> Epsilone
    reduction.nbElementsADepiler = 0;
    reduction.idSymbole = I_LD;
    pileReductions->push_back(reduction);

    //Pour R5 : D -> const Idc
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_D;
    pileReductions->push_back(reduction);

    //Pour R6 : D -> var Idv
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_D;
    pileReductions->push_back(reduction);

    //Pour R7 : Idc -> Idc , id = 
    reduction.nbElementsADepiler = 5;
    reduction.idSymbole = I_Idc;
    pileReductions->push_back(reduction);

    //Pour R8 : Idc -> id = nb
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_Idc;
    pileReductions->push_back(reduction);

    //Pour R9 : Idv -> Idv , id
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_Idv;
    pileReductions->push_back(reduction);

    //Pour R10 : Idv -> id
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_Idv;
    pileReductions->push_back(reduction);

    //Pour R11 : Li -> Li I;
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_Li;
    pileReductions->push_back(reduction);

    //Pour R12 : Li -> Epsilone
    reduction.nbElementsADepiler = 0;
    reduction.idSymbole = I_Li;
    pileReductions->push_back(reduction);

    //Pour R13 : I -> lire id
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R14 : I -> ecrire E
    reduction.nbElementsADepiler = 2;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R15 : I -> id := E
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_I;
    pileReductions->push_back(reduction);

    //Pour R16 : E -> id
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R17 : E -> nb
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R18 : E -> E opA E
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R19 : E -> E opM E
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R20 : E -> ( E )
    reduction.nbElementsADepiler = 3;
    reduction.idSymbole = I_E;
    pileReductions->push_back(reduction);

    //Pour R21 : opA -> pls
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_opA;
    pileReductions->push_back(reduction);

    //Pour R22 : opA -> mns
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_opA;
    pileReductions->push_back(reduction);

    //Pour R23 : opM -> div
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_opM;
    pileReductions->push_back(reduction);

    //Pour R24 : opM -> mul
    reduction.nbElementsADepiler = 1;
    reduction.idSymbole = I_opM;
    pileReductions->push_back(reduction);
}

bool Automate::setFile(vector<string> fileVector)
{
	this->fluxEntrantP = fileVector;

	return true;
}

Programme* Automate::lecture()
/* Fonction lecture :
 * 
 */
{
	currentLexer = Lexer(fluxEntrantP);
	bool expressionAcceptee = false;
	Symbole* ptSymboleSuivant;

	// Initialisation de l'automate
	pileEtats->push_back(new E0);

	//Execution de l'automate a pile
	while(!expressionAcceptee)
	{  
		ptSymboleSuivant = currentLexer.getNext();
		// TEST JULIEN
        //this->affichageEtatAutomate(ptSymboleSuivant);
		expressionAcceptee = pileEtats->back()->transition(*this, ptSymboleSuivant);
	}

	//std::cout << typeid(pileSymboles->back()).name() << '\n';

	return (Programme*)pileSymboles->back();

}

void Automate::affichageEtatAutomate(Symbole* symbole)
{
    cout << "Prochain Symbole à lire : " << symbole->toString() << endl;
    
    cout << "Pile Etats : ";
    for (int i=0; i<(int)pileEtats->size(); i++)
    {
        cout << (pileEtats->at(i))->getNomEtat() << " ";
    }
    cout << endl;

    cout << "Pile Symboles : ";

    for (int i=0; i<(int)pileSymboles->size(); i++)
    {
        cout << (pileSymboles->at(i))->toString() << " ";
    }
    cout << endl;
    cout << "Appuyez sur Entrée pour continuer....";
    getchar();

    cout << "\n" << endl;

}


Variable* Automate::associerIdVariable(Variable* var)
{
	if(pointeurDeclarations==NULL)
	{
		//RAISE EXCEPTION
		pointeurDeclarations = new Ld();
		pointeurDeclarations->setLdNonPresent();

		Variable* newVar = new Variable(var->getNom());
		pointeurDeclarations->ajouterVariableNonDeclaree(newVar);
		return newVar;
	}

	Variable* ptVar = pointeurDeclarations->trouver(var->getNom());
	if(ptVar == NULL)
	{
		//RAISE EXCEPTION
		return new Variable(var->getNom());
	}
	return ptVar;
}