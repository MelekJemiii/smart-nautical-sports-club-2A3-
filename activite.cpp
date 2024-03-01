#include "activite.h"

// activite.cpp

#include "activite.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QObject>
#include <QSqlQueryModel>
#include <QTableWidgetItem>

void activite::afficher_activite(Ui::MainWindow *ui) {
    QSqlQuery query;

    query.prepare("SELECT * FROM ACTIVITE");

    if (query.exec()) {
        ui->tab_activite_modif_2->clearContents();
        ui->tab_activite_modif_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_activite_modif_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_activite_modif_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_activite_modif_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_activite_modif_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void activite::afficher_activite2(Ui::MainWindow *ui) {
    QSqlQuery query;

    query.prepare("SELECT * FROM ACTIVITE");

    if (query.exec()) {
        ui->tab_activite_2->clearContents();
        ui->tab_activite_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_activite_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_activite_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_activite_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_activite_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void activite::ajouter_activite(Ui::MainWindow *ui) {
    QString nom_local, nom_coach;
    nom = ui->nom_activite->text();
    description = ui->description_activite->text();
    type = ui->type_activite->currentText();
    materiel = ui->materiel_activite->currentText();
    date_act = ui->date_activite->date();
    nom_local = ui->id_local_activite->currentText();
    nom_coach = ui->id_coach_activite->currentText();

    QSqlQuery query_local;
    query_local.prepare("SELECT ID FROM LOCAL WHERE NOM=:nom_local");
    query_local.bindValue(":nom_local", nom_local);

    if (query_local.exec() && query_local.next()) {
        id_local = query_local.value(0).toInt();

        QSqlQuery query_coach;
        query_coach.prepare("SELECT ID FROM EMPLOYE WHERE NOM = :nom_coach");
        query_coach.bindValue(":nom_coach", nom_coach);

        if (query_coach.exec() && query_coach.next()) {
            id_coach = query_coach.value(0).toInt();
        } else {
            qDebug() << "Error fetching COACH ID for name:" << nom_coach << query_coach.lastError().text() << query_coach.lastError().databaseText();
        }
    } else {
        qDebug() << "Error fetching LOCAL ID for name:" << nom_local << query_local.lastError().text() << query_local.lastError().databaseText();
    }

    QSqlQuery query;
    QString sql = "INSERT INTO ACTIVITE (NOM, DESCRIPTION, TYPE, DATE_ACT,MATERIEL, ID_LOCAL, ID_COACH) "
                  "VALUES (:nom, :description, :type, :date_act, :materiel,:id_local, :id_coach)";
    query.prepare(sql);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":type", type);
    query.bindValue(":date_act", date_act);
    query.bindValue(":id_local", id_local);
    query.bindValue(":materiel", materiel);
    query.bindValue(":id_coach", id_coach);

    if (query.exec()) {
        qDebug() << "Data inserted successfully.";
        afficher_activite(ui);
        afficher_activite2(ui);
    } else {
        qDebug() << "Error inserting data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void activite::modifier_activite(Ui::MainWindow *ui) {
    QSqlQuery query;
    QString nom_local = ui->id_local_activite_modif->currentText();
    QString nom_coach = ui->id_coach_activite_modif->currentText();
    QSqlQuery query_local;
    query_local.prepare("SELECT ID FROM LOCAL WHERE NOM=:nom_local");
    query_local.bindValue(":nom_local", nom_local);

    if (query_local.exec() && query_local.next()) {
        id_local = query_local.value(0).toInt();

        QSqlQuery query_coach;
        query_coach.prepare("SELECT ID FROM EMPLOYE WHERE NOM = :nom_coach");
        query_coach.bindValue(":nom_coach", nom_coach);

        if (query_coach.exec() && query_coach.next()) {
            id_coach = query_coach.value(0).toInt();
        } else {
            qDebug() << "Error fetching COACH ID for name:" << nom_coach << query_coach.lastError().text() << query_coach.lastError().databaseText();
        }
    } else {
        qDebug() << "Error fetching LOCAL ID for name:" << nom_local << query_local.lastError().text() << query_local.lastError().databaseText();
    }

    query.prepare("UPDATE ACTIVITE SET NOM=:nom, DESCRIPTION=:description, TYPE=:type, DATE_ACT=:date_act,MATERIEL=:materiel, ID_LOCAL=:id_local, ID_COACH=:id_coach WHERE ID=:id");
    query.bindValue(":id", ui->activite_supp->text());
    query.bindValue(":nom", ui->nom_activite_modif->text());
    query.bindValue(":description", ui->description_activite_modif->text());
    query.bindValue(":type", ui->type_activite_modif->currentText());
    query.bindValue(":materiel", ui->materiel_activite_modif->currentText());
    query.bindValue(":date_act", ui->date_activite_modif->date());
    query.bindValue(":id_local", id_local);
    query.bindValue(":id_coach", id_coach);

    if (query.exec()) {
        qDebug() << "Data updated successfully.";
        afficher_activite(ui);
        afficher_activite2(ui);
        ui->activite_supp->clear();
        ui->nom_activite_modif->clear();
        ui->description_activite_modif->clear();
        ui->type_activite_modif->clear();
        ui->materiel_activite_modif->clear();
        ui->date_activite_modif->setDate(QDate::currentDate());
        ui->id_local_activite_modif->clear();
        ui->id_coach_activite_modif->clear();
    } else {
        qDebug() << "Error updating data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void activite::supprimer_activite(Ui::MainWindow *ui) {
    QString id;
    id = ui->activite_supp->text();
    QSqlQuery query;
    QString sql = "DELETE FROM ACTIVITE WHERE ID=:id";

    qDebug() << "Executing SQL query:" << sql;
    qDebug() << "Binding value for :id:" << id;

    query.prepare(sql);
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Delete operation successful. Rows affected:" << query.numRowsAffected();
        afficher_activite(ui);
        afficher_activite2(ui);        ui->activite_supp->clear();
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}

void activite::init_activite(Ui::MainWindow *ui) {
    QSqlQuery query;
    query.prepare("SELECT NOM FROM LOCAL");
    query.exec();

    if (query.isActive()) {
        while (query.next()) {
            QString value = query.value(0).toString();
            ui->id_local_activite->addItem(value);
        }
    } else {
        qDebug() << "Error fetching data from LOCAL table:" << query.lastError().text() << query.lastError().databaseText();
    }

    QSqlQuery query_coach;
    query_coach.prepare("SELECT NOM FROM EMPLOYE");
    query_coach.exec();

    if (query_coach.isActive()) {
        while (query_coach.next()) {
            QString value = query_coach.value(0).toString();
            ui->id_coach_activite->addItem(value);
        }
    } else {
        qDebug() << "Error fetching data from COACH table:" << query_coach.lastError().text() << query_coach.lastError().databaseText();
    }
}

void activite::init_activite2(Ui::MainWindow *ui) {
    QSqlQuery query;
    query.prepare("SELECT NOM FROM LOCAL");
    query.exec();

    if (query.isActive()) {
        while (query.next()) {
            QString value = query.value(0).toString();
            ui->id_local_activite_modif->addItem(value);
        }
    } else {
        qDebug() << "Error fetching data from LOCAL table:" << query.lastError().text() << query.lastError().databaseText();
    }

    QSqlQuery query_coach;
    query_coach.prepare("SELECT NOM FROM COACH");
    query_coach.exec();

    if (query_coach.isActive()) {
        while (query_coach.next()) {
            QString value = query_coach.value(0).toString();
            ui->id_coach_activite_modif->addItem(value);
        }
    } else {
        qDebug() << "Error fetching data from COACH table:" << query_coach.lastError().text() << query_coach.lastError().databaseText();
    }
}
