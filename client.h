#ifndef CLIENT_H
#define CLIENT_H


#include <QString>
#include <QDate>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"


class client {

public:
    QString nom,prenom,mail,adresse,type,gender,niveau;
    double salaire;
    int num;

    QDate dob;
    void ajouter_client(Ui::MainWindow *ui);
    void afficher_client(Ui::MainWindow *ui);
    void init_client(Ui::MainWindow *ui);
    void tri_cli(Ui::MainWindow *ui,QString choix);
    void afficher_client2(Ui::MainWindow *ui);
    void init_client2(Ui::MainWindow *ui);
    void supprimer_client(Ui::MainWindow *ui);
    void modifier_client(Ui::MainWindow *ui);
    void tri_emp(Ui::MainWindow *ui);
    int getColumnIndex(QTableWidget *table, const QString &columnName);

};




#endif // CLIENT_H
