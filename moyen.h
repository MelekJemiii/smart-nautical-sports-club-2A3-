// moyen.h

#ifndef MOYEN_H
#define MOYEN_H

#include <QString>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class moyen
{
public:
    QString nom, description;
    int qte, prix;

    void afficher_moyen(Ui::MainWindow *ui);
    void afficher_moyen2(Ui::MainWindow *ui);
    void ajouter_moyen(Ui::MainWindow *ui);
    void modifier_moyen(Ui::MainWindow *ui);
    void supprimer_moyen(Ui::MainWindow *ui);
    void init_moyen(Ui::MainWindow *ui);
    void init_moyen2(Ui::MainWindow *ui);
};

#endif // MOYEN_H
