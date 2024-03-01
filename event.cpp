// event.cpp

#include "event.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QObject>
#include <QSqlQueryModel>
#include <QTableWidgetItem>

void event::afficher_event(Ui::MainWindow *ui) {
    QSqlQuery query;

    query.prepare("SELECT * FROM EVENT");

    if (query.exec()) {
        ui->tab_event_modif_2->clearContents();
        ui->tab_event_modif_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_event_modif_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_event_modif_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_event_modif_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_event_modif_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}
void event::afficher_event2(Ui::MainWindow *ui) {
    QSqlQuery query;

    query.prepare("SELECT * FROM EVENT");

    if (query.exec()) {
        ui->tab_event_2->clearContents();
        ui->tab_event_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_event_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_event_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_event_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_event_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void event::ajouter_event(Ui::MainWindow *ui) {
    QString nom_local,nom_res;
    nom = ui->nom_event->text();
    description = ui->description_event->text();
    type = ui->type_event->currentText();
    date_event = ui->date_event->date();
    nom_local = ui->id_local_event->currentText();
    nom_res = ui->id_responsable_event->currentText();
    nbr_par = ui->nbr_participants_event->text().toInt();
    QSqlQuery query_local;
    query_local.prepare("SELECT ID FROM LOCAL WHERE NOM=:nom_local");
    query_local.bindValue(":nom_local", nom_local);

    if (query_local.exec() && query_local.next()) {
        id_local = query_local.value(0).toInt();

        QSqlQuery query_res;
        query_res.prepare("SELECT ID FROM EMPLOYE WHERE NOM = :nom_res");
        query_res.bindValue(":nom_res", nom_res);

        if (query_res.exec() && query_res.next()) {
            id_res = query_res.value(0).toInt();
        } else {
            qDebug() << "Error fetching EMPLOYE ID for name:" << nom_res << query_res.lastError().text() << query_res.lastError().databaseText();
        }
    } else {
        qDebug() << "Error fetching LOCAL ID for name:" << nom_local << query_local.lastError().text() << query_local.lastError().databaseText();
    }


                    qDebug() << "responsable ===."<<nom_res <<"id responsable==="<<id_res;
                    qDebug() << "local ===."<<nom_local <<"id local==="<<id_local;
    QSqlQuery query;
    QString sql = "INSERT INTO EVENT (NOM, DESCRIPTION, TYPE, DATE_EVENT, ID_LOCAL, ID_RES, NBR_PARTICIPANTS) "
                  "VALUES (:nom, :description, :type, :date_event, :id_local, :id_responsable, :nbr_participants)";
    query.prepare(sql);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":type", type);
    query.bindValue(":date_event", date_event);
    query.bindValue(":id_local", id_local);
    query.bindValue(":id_responsable", id_res);
    query.bindValue(":nbr_participants", nbr_par);

    if (query.exec()) {
        qDebug() << "Data inserted successfully.";
        afficher_event(ui);
    } else {
        qDebug() << "Error inserting data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void event::modifier_event(Ui::MainWindow *ui) {
   QSqlQuery query;
   QString nom_local = ui->id_local_event_modif->currentText();
   QString nom_res = ui->id_responsable_event_modif->currentText();
   QSqlQuery query_local;
   query_local.prepare("SELECT ID FROM LOCAL WHERE NOM=:nom_local");
   query_local.bindValue(":nom_local", nom_local);

   if (query_local.exec() && query_local.next()) {
       id_local = query_local.value(0).toInt();

       QSqlQuery query_res;
       query_res.prepare("SELECT ID FROM EMPLOYE WHERE NOM = :nom_res");
       query_res.bindValue(":nom_res", nom_res);

       if (query_res.exec() && query_res.next()) {
           id_res = query_res.value(0).toInt();
       } else {
           qDebug() << "Error fetching EMPLOYE ID for name:" << nom_res << query_res.lastError().text() << query_res.lastError().databaseText();
       }
   } else {
       qDebug() << "Error fetching LOCAL ID for name:" << nom_local << query_local.lastError().text() << query_local.lastError().databaseText();
   }
    query.prepare("UPDATE EVENT SET NOM=:nom, DESCRIPTION=:description, TYPE=:type, DATE_EVENT=:date_event, ID_LOCAL=:id_local, ID_RES=:id_res, NBR_PARTICIPANTS=:nbr_par WHERE ID=:id");
    query.bindValue(":id", ui->event_supp->text());
    query.bindValue(":nom", ui->nom_event_modif->text());
    query.bindValue(":description", ui->description_event_modif->text());
    query.bindValue(":type", ui->type_event_modif->currentText());
    query.bindValue(":date_event", ui->date_event_modif->date());
    query.bindValue(":id_local", id_local);
    query.bindValue(":id_res", id_res);
    query.bindValue(":nbr_par", ui->nbr_participants_event_modif->text().toInt());

    if (query.exec()) {
        qDebug() << "Data updated successfully.";
        afficher_event(ui);
        afficher_event2(ui);

        ui->event_supp->clear();
        ui->nom_event_modif->clear();
        ui->description_event_modif->clear();
        ui->type_event_modif->clear();
        ui->date_event_modif->setDate(QDate::currentDate());
        ui->id_local_event_modif->clear();
        ui->id_responsable_event_modif->clear();
        ui->nbr_participants_event_modif->clear();
    } else {
        qDebug() << "Error updating data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void event::supprimer_event(Ui::MainWindow *ui) {
   QString id;
    id = ui->event_supp->text();
    QSqlQuery query;
    QString sql = "DELETE FROM EVENT WHERE ID=:id";

    qDebug() << "Executing SQL query:" << sql;
    qDebug() << "Binding value for :id:" << id;

    query.prepare(sql);
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Delete operation successful. Rows affected:" << query.numRowsAffected();
        afficher_event(ui);
        ui->event_supp->clear();
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}

void event::init_event(Ui::MainWindow *ui) {
   QSqlQuery query;
    query.prepare("SELECT NOM FROM LOCAL");
    query.exec();

    if (query.isActive()) {
        while (query.next()) {
            QString value = query.value(0).toString();
            ui->id_local_event->addItem(value);
        }
    } else {
        qDebug() << "Error fetching data from LOCAL table:" << query.lastError().text() << query.lastError().databaseText();
    }

    QSqlQuery query_res;
    query_res.prepare("SELECT NOM FROM EMPLOYE");
    query_res.exec();

    if (query_res.isActive()) {
        while (query_res.next()) {
            QString value = query_res.value(0).toString();
            ui->id_responsable_event->addItem(value);
        }
    } else {
        qDebug() << "Error fetching data from EMPLOYE table:" << query_res.lastError().text() << query_res.lastError().databaseText();
    }
}
void event::init_event2(Ui::MainWindow *ui) {
   QSqlQuery query;
    query.prepare("SELECT NOM FROM LOCAL");
    query.exec();

    if (query.isActive()) {
        while (query.next()) {
            QString value = query.value(0).toString();
            ui->id_local_event_modif->addItem(value);
        }
    } else {
        qDebug() << "Error fetching data from LOCAL table:" << query.lastError().text() << query.lastError().databaseText();
    }

    QSqlQuery query_res;
    query_res.prepare("SELECT NOM FROM EMPLOYE");
    query_res.exec();

    if (query_res.isActive()) {
        while (query_res.next()) {
            QString value = query_res.value(0).toString();
            ui->id_responsable_event_modif->addItem(value);
        }
    } else {
        qDebug() << "Error fetching data from EMPLOYE table:" << query_res.lastError().text() << query_res.lastError().databaseText();
    }
}
