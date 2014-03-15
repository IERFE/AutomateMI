#ifndef TRANSITION_H
#define TRANSITION_H

#include "etat.h"
#include "string"
using namespace std;
class Etat;// Evite les erreurs du compilateur, pour l'utilisation de la classe Etat dans la class Transition et vice versa
class Transition{
    /** *************************************************************************************** \
     * CLASSE DE L'OBJET ETAT :
     * Permet de representer l'état sous forme d'objet pour effecteur des traitements
     * *****************************************************************************************/
    // Contien le nom de la transition
    string nom;
    // Pointeur sur l'état courant
    Etat *etatCourant;
    // Pointeur sur l'état suivant
    Etat *etatSuivant;

public:
    Transition();

    void setNom(const string &Nom);
    string getNom();
    void setEtatCourant(const string *Nom);
    Etat *getEtatCourant();
    void setEtatSuivant(const string *Nom);
    Etat *getEtatSuivant();
};

#endif // TRANSITION_H
