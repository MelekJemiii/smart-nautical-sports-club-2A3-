#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QDate>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class event
{
public:
    QString nom, description, type;
    QDate date_event;
    int id_local, id_res, nbr_par;

    void afficher_event(Ui::MainWindow *ui);
    void afficher_event2(Ui::MainWindow *ui);
    void init_event(Ui::MainWindow *ui);
    void init_event2(Ui::MainWindow *ui);
    void ajouter_event(Ui::MainWindow *ui);
    void modifier_event(Ui::MainWindow *ui);
    void supprimer_event(Ui::MainWindow *ui);
};

#endif // EVENT_H
