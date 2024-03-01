#include "local.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QObject>
#include <QSqlQueryModel>
#include <QTableWidgetItem>

void local::afficher_local(Ui::MainWindow *ui) {


    QSqlQuery query;

    query.prepare("SELECT * FROM LOCAL");


    if (query.exec()) {
        ui->tab_loc_modif_2->clearContents();
        ui->tab_loc_modif_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_loc_modif_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_loc_modif_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_loc_modif_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_loc_modif_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}


void local::afficher_local2(Ui::MainWindow *ui) {


    QSqlQuery query;

    query.prepare("SELECT * FROM LOCAL");


    if (query.exec()) {
        ui->tab_loc_2->clearContents();
        ui->tab_loc_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_loc_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_loc_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_loc_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_loc_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}


void local::ajouter_local(Ui::MainWindow *ui) {




            nom = ui->nom_loc->text();
            description = ui->description_loc->text();
            type = ui->type_loc->currentText();
            adresse = ui->adresse_loc->text();
            QString nom_res = ui->id_respon_loc->currentText();
            QSqlQuery query_res;
            QString sql1 = "SELECT ID FROM EMPLOYE WHERE NOM=:NOM_RES ";
            query_res.prepare(sql1);
            query_res.bindValue(":NOM_RES", nom_res);
            qDebug() << "SQL Query for Employee ID: " << sql1;
            if (query_res.exec()) {
                if (query_res.next()) {
                    id_respon = query_res.value(0).toInt();
                    qDebug() << "Employee ID found: " << id_respon;
                } else {
                    qDebug() << "Employee not found for name: " << nom_res;
                }
            } else {
                qDebug() << "Error fetching Employee ID:" << query_res.lastError().text() << query_res.lastError().databaseText();
            }


            QSqlQuery query;
            QString sql = "INSERT INTO LOCAL ( NOM,DESCRIPTION, ADRESSE, ID_RESPON, TYPE) "
                          "VALUES (:nom_loc, :description_loc, :adresse_loc, :id_respo_loc, :type_loc)";
            query.prepare(sql);
            query.bindValue(":nom_loc", nom);
            query.bindValue(":description_loc", description);
            query.bindValue(":adresse_loc", adresse);
            query.bindValue(":type_loc", type);
            query.bindValue(":id_respo_loc", id_respon);

            if (query.exec()) {
                qDebug() << "Data inserted successfully.";
                afficher_local(ui);
                afficher_local2(ui);
            } else {
                qDebug() << "Error inserting data:" << query.lastError().text() << query.lastError().databaseText();
            }


}

void local::init_local(Ui::MainWindow *ui) {





    QSqlQuery query11;
    query11.prepare("SELECT NOM FROM EMPLOYE");
    query11.exec();

    // Check if the query is successful
    if (query11.isActive()) {
        // Iterate over all records in the result set
        while (query11.next()) {
            // Iterate over the columns and add them to the ComboBox
            int columnCount = query11.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query11.value(i).toString();
                ui->id_respon_loc->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from Local table:" << query11.lastError().text() << query11.lastError().databaseText();
    }


}

void local::modifier_local(Ui::MainWindow *ui){
    QString nom_res = ui->res_loc_mof->currentText();
    QSqlQuery getIdQuery3;
    getIdQuery3.prepare("SELECT ID FROM EMPLOYE WHERE NOM=:NOM_RES");
    getIdQuery3.bindValue(":NOM_RES", nom_res);

    if (getIdQuery3.exec() && getIdQuery3.next()) {
        QSqlQuery query;
        query.prepare("UPDATE LOCAL SET NOM=:nom, DESCRIPTION=:description, ADRESSE=:adresse, TYPE=:type, ID_RESPON=:id_res WHERE ID=:id");
        query.bindValue(":id", ui->id_loc_modif->text());
        query.bindValue(":nom", ui->nom_loc_mof->text());
        query.bindValue(":description", ui->description_loc_mof->text());
        query.bindValue(":adresse", ui->adresse_loc_mof->text());
        query.bindValue(":type", ui->type_loc_mof->currentText());
        query.bindValue(":id_res", getIdQuery3.value(0).toInt());

        if (query.exec()) {
            qDebug() << "Data updated successfully.";
            afficher_local2(ui);
            afficher_local(ui);

                    ui->loc_supp->clear();
            ui->nom_loc_mof->clear();
             ui->description_loc_mof->clear();
             ui->adresse_loc_mof->clear();
             ui->type_loc_mof->clear();
             ui->id_loc_modif->clear();
             ui->res_loc_mof->clear();
            // You may add code here to refresh or display the updated data as needed
        } else {
            qDebug() << "Error updating data:" << query.lastError().text() << query.lastError().databaseText();
        }
    } else {
        qDebug() << "Error executing query to get IDs:"<<nom_res << getIdQuery3.lastError().text() << getIdQuery3.lastError().databaseText();
    }

}
void local::init_local2(Ui::MainWindow *ui) {

    QSqlQuery query11;
    query11.prepare("SELECT NOM FROM EMPLOYE");
    query11.exec();

    // Check if the query is successful
    if (query11.isActive()) {
        // Iterate over all records in the result set
        while (query11.next()) {
            // Iterate over the columns and add them to the ComboBox
            int columnCount = query11.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query11.value(i).toString();
                ui->res_loc_mof->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query11.lastError().text() << query11.lastError().databaseText();
    }



}



void local::supprimer_local(Ui::MainWindow *ui) {
    QString id;
    id = ui->loc_supp->text();
    QSqlQuery query;
    QString sql = "DELETE FROM LOCAL WHERE ID=:id";

    qDebug() << "Executing SQL query:" << sql;
    qDebug() << "Binding value for :id:" << id;

    query.prepare(sql);
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Delete operation successful. Rows affected:" << query.numRowsAffected();
        afficher_local(ui);
        afficher_local2(ui);
        ui->loc_supp->clear();
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}


