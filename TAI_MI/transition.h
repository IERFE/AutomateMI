#ifndef TRANSITION_H
#define TRANSITION_H

#include "etat.h"

class Transition{
    /** *************************************************************************************** \
     * CLASSE DE L'OBJET ETAT :
     * Permet de representer l'état sous forme d'objet pour effecteur des traitements
     * *****************************************************************************************/
    // Contien le nom de la transition
    char nom;
    // Pointeur sur l'état courant
    Etat etatCourant;
    // Pointeur sur l'état suivant
    Etat etatSuivant;

public:
    Transition();
};

#endif // TRANSITION_H
