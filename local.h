#ifndef LOCAL_H
#define LOCAL_H


#include <QString>
#include <QDate>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class local
{
public:

    QString nom,description,adresse,type;
    int id_respon;
    void afficher_local(Ui::MainWindow *ui);
    void init_local(Ui::MainWindow *ui);
    void tri_local(Ui::MainWindow *ui,QString choix);
    void init_local2(Ui::MainWindow *ui);
    void afficher_local2(Ui::MainWindow *ui);
    void ajouter_local(Ui::MainWindow *ui);
    void supprimer_local(Ui::MainWindow *ui);
    void modifier_local(Ui::MainWindow *ui);

};

#endif // LOCAL_H
