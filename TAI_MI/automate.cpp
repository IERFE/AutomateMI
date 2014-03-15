#include "automate.h"

Automate::Automate(){

}
void Automate::ajouterUnEtat(Etat &etat){
    /** ****************************************************************************************\
     * METHODE : Permet l'ajout d'un objet Etat dans la liste de tout les etats de l'automate
     * *****************************************************************************************/
    // Ajoute l'etat dans en tête de la liste de tous les états de l'automate
    listeDeTousLesEtats.push_front(etat);

    if(etat.isInitial())
        listeDeTousLesEtatsInitiaux.push_front(&etat);
    if(etat.isTerminal())
        listeDeTousLesEtatsTerminaux.push_front(&etat);
}
