#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "etat.h"
#include "transition.h"
class Etat;
class Transition;
class Automate{
    /** *************************************************************************************** \
     * CLASSE DE L'OBJET AUTOMATE :
     * Permet de representer l'automate sous forme d'objet pour effecteur des traitement dessus
     * *****************************************************************************************/
    // Contient tous les etats
    list <Etat> listeDeTousLesEtats;
    // Contient tous les etats initiaux
    list <Etat*> listeDeTousLesEtatsInitiaux;
    // Contient tous les etats terminaux
    list <Etat*> listeDeTousLesEtatsTerminaux;
public:
    Automate();
    void ajouterUnEtat(Etat &etat);

};

#endif // AUTOMATE_H
