#include "analysesyntaxique.h"
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
AnalyseSyntaxique::AnalyseSyntaxique(){
    /** **************
     * CONSTRUCTEUR
     * ***************/

    genererUnAutomate("Fichier Automate/Test1.txt");
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
Automate & AnalyseSyntaxique::genererUnAutomate(const string &liensDuFichierTexte){
     /** ********************************************************************************************************
      * CETTE METHODE PERMET DE GENERER UN AUTOMATE A PARTIR D'UN FICHIER TEXTE, SELON UNE SYNTAXTE PARTICULIERE
      * *********************************************************************************************************/

    // LECTURE DU FICHIER TEXTE DE L'AUTOMATE
    queue<string> queueFichierTexte=lectureDuFichierTexte(liensDuFichierTexte);

    // CREATION DE L'OBJET AUTOMATE
    Automate *automate=new Automate;

    // BOUCLE QUI PERMET DE PARCOURIR LA QUEUE, TANT QUE CELLE CI N'EST PAS VIDE
    while(queueFichierTexte.empty()){
        string ligne=queueFichierTexte.front();


        if(ligne.find("ETATS:")){
            ////////////////////////////////////////////////////
            // * SI LA LIGNE CONTIENT LE MARQUEUR "ETATS:"  * //
            ////////////////////////////////////////////////////

            // SUPRIME LE MARQUEUR "ETAT:"
            ligne.erase(0,6);

            // ON SEPARE CHAQUE ETAT EN FONCTION DU DELIMITEUR ','
            queue<string> queueNomsEtats=split(ligne,",");

            // BOUCLE QUI PERMET DE CREE DES ETATS DANS L'AUTOMATE
            while (!queueNomsEtats.empty()) {
                automate->ajouterUnEtat(queueNomsEtats.front());
                queueNomsEtats.pop();
            }
        }
        else if(ligne.find("ETATS INITIAL:")){
            ////////////////////////////////////////////////////////////
            // * SI LA LIGNE CONTIENT LE MARQUEUR "ETATS  INITIAL:" * //
            ////////////////////////////////////////////////////////////

            // SUPRIME LE MARQUEUR "ETAT:"
            ligne.erase(0,14);

            // ON SEPARE CHAQUE ETAT INITIAL EN FONCTION DU DELIMITEUR ','
            queue<string> queueNomsEtats=split(ligne,",");

            // BOUCLE QUI PERMET DE CREE DES ETATS DANS L'AUTOMATE
            while (!queueNomsEtats.empty()) {

                /// SI ON N'A PAS REUSSI A LE RENDRE TERMINAL, SELA VEUT DIRE QUE L'ETAT NA PAS ETE AJOUTER DANS LA LISTE DE TOUTS LES ETAT, DONC ON DECLENCHE UNE EXEPTION
                /// CELA PEUT ETRE DU A UNE ETRREUR DE SYNTAXE DU FICHIER AUTOMATE
                if(!automate->rendreInitialUnEtat(queueNomsEtats.front()))
                    throw "Erreur : Imposible de configurer en tant q'etat terminal, l'etat '"+queueNomsEtats.front()+"' (Cela peut etre du a une erreur de syntaxe du fichier : '"+liensDuFichierTexte+"').";

                queueNomsEtats.pop();
            }
        }
        // SUPPRIME LA LIGNE ( LA TETE DE LA QUEUE )
        queueFichierTexte.pop();
    }

    return *automate;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
queue<string> &AnalyseSyntaxique::lectureDuFichierTexte(const string &liensDuFichierTexte){
    /** *****************************************************************************
     * CETTE METHODE PERMET DE METRE CHAQUE LIGNE DU FICHIER TEXTE DANS UNE QUEUE
     * *****************************************************************************/

    // CREATION D'UN OBJET DE TYPE ifstream POUR LA LECTURE DU FICHIER TEXTE DE L'AUTOMATE
    ifstream fichierTexte(liensDuFichierTexte.c_str());

    /// SI ON N'A PAS REUSSI A LIRE LE FICHIER TEXTE, ON DECLENCHE UN EXEPTION
    if (!fichierTexte.is_open()) throw "Erreur l'ors de l'ouverture du fichier : '"+liensDuFichierTexte+"'.";
    /// SI LE FICHIER LE FICHIER TEXTE EST VIDE, ON DECLENCHE UN EXEPTION
    if (!fichierTexte.tellg()==0) throw "Erreur le fichier : '"+liensDuFichierTexte+"', est vide.";

    // CREATION D'UN OBJET DE TYPE QUEUE <STRING> QUI VAS CONTENIR CHAQUE LIGNE DU FICHIER TEXTE DE L'AUTMATE
    queue<string> *queueFichierTexte=new queue<string>;

    // CREATION D'UN VARIABLE LINE QUI VAS CAONTENIR LA LIGNE DE CHAQUE ITERATION DE LA BOUCLE
    string ligne;

    // BOUCLE QUI PERMET DE PARCOURIR TOUT LE FICHIER TEXTE DE L'AUTOMATE LIGNE PAR LIGNE
    while (std::getline(fichierTexte,ligne)){
        // AJOUT DE LA LIGNE DANS LA QUEUE
        queueFichierTexte->push(ligne);
    }

    fichierTexte.close();

    return *queueFichierTexte;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
queue<string> &AnalyseSyntaxique::split(const string & texte,const string & delimiteur){
    /** ********************************************************************************************************************************************
     * CETTE METHODE PERMET DE SEPARER PAR RAPORT A UN DELIMITEUR, UNE CHAINE DE CARACTERE EN SOUS CHAINNE DE DE CARACTERE CONTENUE DANS UNE QUEUE
     * ********************************************************************************************************************************************/

     /// SI LA CHAINE DE CARACTERE A SEPARER EST VIDE ON DECLENCHE UNE EXEPTION
     if(texte.empty()) throw "Erreur : la chaine de caractere à 'speparer' est vide.";

     // CREATION DE LA QUEUE QUI VAS CONTENIR LES CHAINE DE CARACTERE SEPARER PAR LE DELIMITEUR
     queue<string> *queueSplitResult=new queue<string>;

     unsigned int marqeurFin;
     string texteTemporaire=texte;

    // BOUCLE QUI PERMET DE PARCOURIR TOUT LA CHAINE DE CARACTERE POUR ENSUITE LA SEPARER SELON LA POSITION DU DELIMITEUR
     while((marqeurFin=texteTemporaire.find(delimiteur))!=std::string::npos){

         // RECUPERER LA CHAINE DE CARACTERE QUI SE TROUVE AVANT LE DELIMITEUR
         string texteSepare=texteTemporaire.substr(0,marqeurFin);

          // SUPPRME LA CHAINE DE CARACTERE DU TEXTE A TRAITER
         texteTemporaire.erase(0,marqeurFin+1);

         // AJOUTE DANS LA QUEUE LA SOUS CHAINE DE CARACTERE QUI CE TROUVE ANVANT LE DELIMITEUR
         queueSplitResult->push(texteSepare);
     }

     // AJOUTE LA FIN DANS LA QUEUD
     queueSplitResult->push(texteTemporaire);

     // REVOIE LE CONTENUE DU POINTEUR
     return *queueSplitResult;
}
