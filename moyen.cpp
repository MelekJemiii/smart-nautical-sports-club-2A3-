// moyen.cpp

#include "moyen.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QObject>
#include <QSqlQueryModel>
#include <QTableWidgetItem>

void moyen::afficher_moyen(Ui::MainWindow *ui) {
    QSqlQuery query;

    query.prepare("SELECT * FROM MOYEN");

    if (query.exec()) {
        ui->tab_moyen_modif_2->clearContents();
        ui->tab_moyen_modif_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_moyen_modif_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_moyen_modif_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_moyen_modif_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_moyen_modif_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void moyen::afficher_moyen2(Ui::MainWindow *ui) {
    QSqlQuery query;

    query.prepare("SELECT * FROM MOYEN");

    if (query.exec()) {
        ui->tab_moyen_2->clearContents();
        ui->tab_moyen_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_moyen_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_moyen_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_moyen_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_moyen_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void moyen::ajouter_moyen(Ui::MainWindow *ui) {
    nom = ui->nom_moyen->text();
    description = ui->description_moyen->text();
    qte = ui->qte_moyen->text().toInt();
    prix = ui->prix_moyen->text().toInt();

    QSqlQuery query;
    QString sql = "INSERT INTO MOYEN (NOM, DESCRIPTION, QTE, PRIX_UNIT) "
                  "VALUES (:nom, :description, :qte, :prix)";
    query.prepare(sql);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":qte", qte);
    query.bindValue(":prix", prix);

    if (query.exec()) {
        qDebug() << "Data inserted successfully.";
        afficher_moyen(ui);
        afficher_moyen2(ui);
    } else {
        qDebug() << "Error inserting data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void moyen::modifier_moyen(Ui::MainWindow *ui) {
    QSqlQuery query;
    query.prepare("UPDATE MOYEN SET NOM=:nom, DESCRIPTION=:description, QTE=:qte, PRIX_UNIT=:prix WHERE ID=:id");
    query.bindValue(":id", ui->moyen_supp->text());
    query.bindValue(":nom", ui->nom_moyen_modif->text());
    query.bindValue(":description", ui->description_moyen_modif->text());
    query.bindValue(":qte", ui->qte_moyen_modif->text().toInt());
    query.bindValue(":prix", ui->prix_moyen_modif->text().toInt());

    if (query.exec()) {
        qDebug() << "Data updated successfully.";
        afficher_moyen(ui);
        afficher_moyen2(ui);

        ui->moyen_supp->clear();
        ui->nom_moyen_modif->clear();
        ui->description_moyen_modif->clear();
        ui->qte_moyen_modif->clear();
        ui->prix_moyen_modif->clear();
    } else {
        qDebug() << "Error updating data:" << query.lastError().text() << query.lastError().databaseText();
    }
}

void moyen::supprimer_moyen(Ui::MainWindow *ui) {
    QString id;
    id = ui->moyen_supp->text();
    QSqlQuery query;
    QString sql = "DELETE FROM MOYEN WHERE ID=:id";

    qDebug() << "Executing SQL query:" << sql;
    qDebug() << "Binding value for :id:" << id;

    query.prepare(sql);
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Delete operation successful. Rows affected:" << query.numRowsAffected();
        afficher_moyen(ui);
        afficher_moyen2(ui);
        ui->moyen_supp->clear();
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}



