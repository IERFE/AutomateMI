#ifndef ETAT_H
#define ETAT_H

#include "list"
//#include "transition.h"
#include "string"

using namespace std;

class Etat{
    /** *************************************************************************************** \
     * CLASSE DE L'OBJET ETAT :
     * Permet de representer l'état sous forme d'objet pour effecteur des traitements
     * *****************************************************************************************/
    // Contient le nom de l'etats
    string nom;
    // Contient toutes les transitions appartenant a l'état
    //list <Transition*> listeDeToutesLesTransition;

public:
    Etat();

};

#endif // ETAT_H
