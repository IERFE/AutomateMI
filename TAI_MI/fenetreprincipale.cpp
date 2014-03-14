#include "fenetreprincipale.h"
#include "ui_fenetreprincipale.h"

fenetrePrincipale::fenetrePrincipale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fenetrePrincipale)
{
    ui->setupUi(this);
}

fenetrePrincipale::~fenetrePrincipale()
{
    delete ui;
}
