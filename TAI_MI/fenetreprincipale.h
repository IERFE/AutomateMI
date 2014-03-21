#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include <QMainWindow>
#include "analysesyntaxique.h"
#include <QMessageBox>
namespace Ui {
class fenetrePrincipale;
}

class fenetrePrincipale : public QMainWindow
{
    Q_OBJECT

public:
    explicit fenetrePrincipale(QWidget *parent = 0);
    ~fenetrePrincipale();

private:
    Ui::fenetrePrincipale *ui;
};

#endif // FENETREPRINCIPALE_H
