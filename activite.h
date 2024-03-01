#ifndef ACTIVITE_H
#define ACTIVITE_H

#include <QString>
#include <QDate>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class activite
{
public:
    QString nom, description, type,materiel;
    int id_coach, id_local;
    QDate date_act;

    void afficher_activite(Ui::MainWindow *ui);
    void afficher_activite2(Ui::MainWindow *ui);
    void ajouter_activite(Ui::MainWindow *ui);
    void modifier_activite(Ui::MainWindow *ui);
    void supprimer_activite(Ui::MainWindow *ui);
    void init_activite(Ui::MainWindow *ui);
    void init_activite2(Ui::MainWindow *ui);
};

#endif // ACTIVITE_H
