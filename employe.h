#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QDate>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"


class employe {

public:
    QString nom,prenom,mail,adresse,poste,gender,type,id_local,id_activite;
    double salaire;
    QDate dob;
    void ajouter_employe(Ui::MainWindow *ui);
    void afficher_employe(Ui::MainWindow *ui);
    void supprimer_employe(Ui::MainWindow *ui);
    void modifier_employe(Ui::MainWindow *ui);
    void init_employe(Ui::MainWindow *ui);
    void init_employe2(Ui::MainWindow *ui);
    void afficher_employe2(Ui::MainWindow *ui);
    void tri_emp(Ui::MainWindow *ui,QString choix);
    int getColumnIndex(QTableWidget *table, const QString &columnName);

};

#endif // EMPLOYE_H
