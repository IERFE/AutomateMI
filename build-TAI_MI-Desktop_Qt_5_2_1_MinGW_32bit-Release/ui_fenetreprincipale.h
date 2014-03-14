/********************************************************************************
** Form generated from reading UI file 'fenetreprincipale.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREPRINCIPALE_H
#define UI_FENETREPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fenetrePrincipale
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *fenetrePrincipale)
    {
        if (fenetrePrincipale->objectName().isEmpty())
            fenetrePrincipale->setObjectName(QStringLiteral("fenetrePrincipale"));
        fenetrePrincipale->resize(400, 300);
        menuBar = new QMenuBar(fenetrePrincipale);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        fenetrePrincipale->setMenuBar(menuBar);
        mainToolBar = new QToolBar(fenetrePrincipale);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        fenetrePrincipale->addToolBar(mainToolBar);
        centralWidget = new QWidget(fenetrePrincipale);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        fenetrePrincipale->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(fenetrePrincipale);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        fenetrePrincipale->setStatusBar(statusBar);

        retranslateUi(fenetrePrincipale);

        QMetaObject::connectSlotsByName(fenetrePrincipale);
    } // setupUi

    void retranslateUi(QMainWindow *fenetrePrincipale)
    {
        fenetrePrincipale->setWindowTitle(QApplication::translate("fenetrePrincipale", "fenetrePrincipale", 0));
    } // retranslateUi

};

namespace Ui {
    class fenetrePrincipale: public Ui_fenetrePrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREPRINCIPALE_H
