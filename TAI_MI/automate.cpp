#include "automate.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
Automate::Automate(){

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void Automate::ajouterUnEtat(Etat &etat){
    /** ****************************************************************************************\
     * METHODE : Permet l'ajout d'un objet Etat dans la liste de tout les etats de l'automate
     * *****************************************************************************************/
    // VERIFIER SI LE NOM DE L4ETAT N4EXISTE PAS DEJA
    // Ajoute l'etat dans en tête de la liste de tous les états de l'automate
    listeDeTousLesEtats.push_front(etat);

    if(etat.isInitial())
        listeDeTousLesEtatsInitiaux.push_front(&etat);
    if(etat.isTerminal())
        listeDeTousLesEtatsTerminaux.push_front(&etat);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void Automate::ajouterUnEtat(const string &nomEtat){
    /** ****************************************************************************************\
     * METHODE : Permet l'ajout d'un objet Etat dans la liste de tout les etats de l'automate
     * *****************************************************************************************/
    Etat etat(nomEtat);
    ajouterUnEtat(etat);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Automate::rendreInitialUnEtat(Etat &etat){
    /** *****************************************************************************
     * METHODE :
     *  PERMET DE CHERCHER L'ETAT A RENDRE INITIAL DANS LA LISTE DES ETATS.
     * RESULTAT :
     * SI L'ETAT EXISTE LA METHODE RENVOIE TRUE
     * SI L'ETAT N'EXISTEPAS LA METHODE RENVOIE FALSE
     * *****************************************************************************/

    // BOUCLE POUR PARCOURIR LA LISTE DES ETATS DE DEBUT JUSQU'A LA FIN
    for(list<Etat>::iterator index = listeDeTousLesEtats.begin(); index != listeDeTousLesEtats.end(); index++) {

        /// SI UN ETATS DEJA PRESENT DANS LA LISTE A LE MEME NOM
        if(index->getNom()==etat.getNom()){

            // ON TRANSFORME L'ETAT EN ETAT TERMINAL
            index->setTerminal(true);

            return true;
        }
    }
    return false;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Automate::rendreInitialUnEtat(const string &nomEtat){
    /** *****************************************************************************
     * METHODE :
     *  PERMET DE CHERCHER L'ETAT A RENDRE INITIAL DANS LA LISTE DES ETATS.
     * RESULTAT :
     * SI L'ETAT EXISTE LA METHODE RENVOIE TRUE
     * SI L'ETAT N'EXISTEPAS LA METHODE RENVOIE FALSE
     * *****************************************************************************/

    // BOUCLE POUR PARCOURIR LA LISTE DES ETATS DE DEBUT JUSQU'A LA FIN
    for(list<Etat>::iterator index = listeDeTousLesEtats.begin(); index != listeDeTousLesEtats.end(); index++) {

        /// SI UN ETATS DEJA PRESENT DANS LA LISTE A LE MEME NOM
        if(index->getNom()==nomEtat){

             // ON TRANSFORME L'ETAT EN ETAT TERMINAL
            index->setTerminal(true);

            return true;
        }
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////
