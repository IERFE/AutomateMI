#ifndef ANALYSESYNTAXIQUE_H
#define ANALYSESYNTAXIQUE_H
#include "automate.h"
#include "string.h"
#include "queue"
#include <iostream>
#include <fstream>
using namespace std;

class AnalyseSyntaxique{
    /*** ***************************************************************************
     * CETTE CLASSE PERMET DE GENERER UN OBJECT AUTOMATE A PARTIR D'UN FICHIER TEXTE
     * *****************************************************************************/
public:
    AnalyseSyntaxique();
    Automate &genererUnAutomate(const string &liensDuFichierTexte);
private :
    queue<string> &lectureDuFichierTexte(const string & liensDuFichierTexte );
    queue<string> &split(const string & texte,const string & delimiteur);

};

#endif // ANALYSESYNTAXIQUE_H
