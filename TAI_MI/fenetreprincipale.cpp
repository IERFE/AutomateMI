#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

fenetrePrincipale::fenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fenetrePrincipale)
{
    ui->setupUi(this);
    try {
        AnalyseSyntaxique a;
    }
    catch (string &erreur) {
        QMessageBox msgBox;
        msgBox.setText(QString::fromUtf8(erreur.c_str()));
        msgBox.exec();
    }


}

fenetrePrincipale::~fenetrePrincipale()
{
    delete ui;
}
