#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "etat.h"
#include "transition.h"

class Automate{
    /** *************************************************************************************** \
     * CLASSE DE L'OBJET AUTOMATE :
     * Permet de representer l'automate sous forme d'objet pour effecteur des traitement dessus
     * *****************************************************************************************/
    // Contient tous les etats
    list <Transition> listeDeTousLesEtats;
    // Contient tous les etats initiaux
    list <Transition*> listeDeTousLesEtatsInitiaux;
    // Contient tous les etats terminaux
    list <Transition*> listeDeTousLesEtatsTerminaux;
    // Contient toutes les transitions
    list <Transition> listeDeToutesLesTransition;
public:
    Automate();
};

#endif // AUTOMATE_H
