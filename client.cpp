#include "client.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QObject>
#include <QSqlQueryModel>
#include <QTableWidgetItem>

void client::afficher_client(Ui::MainWindow *ui) {


    QSqlQuery query;

    query.prepare("SELECT * FROM CLIENT");


    if (query.exec()) {
        ui->tab_client_2->clearContents();
        ui->tab_client_2->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_client_2->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_client_2->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_client_2->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_client_2->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}
void client::init_client(Ui::MainWindow *ui) {
    QSqlQuery query11;
    query11.prepare("SELECT TYPE FROM TYPE_ABON");
    query11.exec();

    // Check if the query is successful
    if (query11.isActive()) {
        // Iterate over all records in the result set
        while (query11.next()) {
            // Iterate over the columns and add them to the ComboBox
            int columnCount = query11.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query11.value(i).toString();
                ui->type->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query11.lastError().text() << query11.lastError().databaseText();
    }
    //activite role
    QSqlQuery query;
    query.prepare("SELECT NIV FROM NIVEAU");
    query.exec();

    // Check if the query is successful
    if (query.isActive()) {
        // Iterate over all records in the result set
        while (query.next()) {
            // Iterate over the columns and add them to the ComboBox
            int columnCount = query.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query.value(i).toString();
                ui->niveau->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query.lastError().text() << query.lastError().databaseText();
    }


//combobox role
QSqlQuery query1;
query1.prepare("SELECT TYPE FROM ROLE");
query1.exec();

// Check if the query is successful
if (query1.isActive()) {
    // Iterate over all records in the result set
    while (query1.next()) {
        // Iterate over the columns and add them to the ComboBox
        int columnCount = query1.record().count();
        for (int i = 0; i < columnCount; ++i) {
            QString value = query1.value(i).toString();
            ui->role_emp->addItem(value);
        }
    }
} else {
    qDebug() << "Error fetching data from ROLE table:" << query1.lastError().text() << query1.lastError().databaseText();
}
}


void client::ajouter_client(Ui::MainWindow *ui) {

    niveau = ui->niveau->currentText();


    type = ui->type->currentText();




            prenom = ui->prenom_client->text();
            nom = ui->nom_client->text();
            mail = ui->mail_client->text();
            adresse = ui->adresse_client->text();
            gender = ui->gender_client->currentText();
            num = ui->tel_client->text().toInt();
            dob = ui->dob_client->date();

            QSqlQuery query;
            QString sql = "INSERT INTO CLIENT ( NOM, PRENOM, ADRESSE, GENDER, MAIL, TEL, NIVEAU, DOB, TYPE) "
                          "VALUES (:nom, :prenom, :adresse, :gender, :mail, :num, :niveau, :dob, :type)";
            query.prepare(sql);
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);
            query.bindValue(":adresse", adresse);
            query.bindValue(":mail", mail);
            query.bindValue(":gender", gender);
            query.bindValue(":niveau", niveau);
            query.bindValue(":num", num);
            query.bindValue(":dob", dob);
            query.bindValue(":type", type);

            if (query.exec()) {
                qDebug() << "Data inserted successfully.";
                afficher_client(ui);
                afficher_client2(ui);
            } else {
                qDebug() << "Error inserting data:" << query.lastError().text() << query.lastError().databaseText();
            }


}
void client::afficher_client2(Ui::MainWindow *ui) {



    QSqlQuery query;

    query.prepare("SELECT * FROM CLIENT");


    if (query.exec()) {
        ui->tab_client->clearContents();
        ui->tab_client->setRowCount(0);
        int columnCount = query.record().count();
        ui->tab_client->setColumnCount(columnCount);

        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(col));
            ui->tab_client->setHorizontalHeaderItem(col, headerItem);
        }

        int row = 0;
        while (query.next()) {
            ui->tab_client->insertRow(row);

            for (int col = 0; col < columnCount; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                ui->tab_client->setItem(row, col, item);
            }

            ++row;
        }

        qDebug() << "Data retrieved and displayed successfully.";
    } else {
        qDebug() << "Error fetching data:" << query.lastError().text() << query.lastError().databaseText();
    }
}


void client::supprimer_client(Ui::MainWindow *ui) {
    QString id;
    id = ui->client_supp->text();
    QSqlQuery query;
    QString sql = "DELETE FROM CLIENT WHERE ID=:id";

    qDebug() << "Executing SQL query:" << sql;
    qDebug() << "Binding value for :id:" << id;

    query.prepare(sql);
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Delete operation successful. Rows affected:" << query.numRowsAffected();
        afficher_client(ui);
        afficher_client2(ui);
        ui->client_supp->clear();
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}







void client::init_client2(Ui::MainWindow *ui) {

    QSqlQuery query11;
    query11.prepare("SELECT TYPE FROM TYPE_ABON");
    query11.exec();

    // Check if the query is successful
    if (query11.isActive()) {
        // Iterate over all records in the result set
        while (query11.next()) {
            // Iterate over the columns and add them to the ComboBox
            int columnCount = query11.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query11.value(i).toString();
                ui->type_cli_modif->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query11.lastError().text() << query11.lastError().databaseText();
    }
    //activite role
    QSqlQuery query;
    query.prepare("SELECT NIV FROM NIVEAU");
    query.exec();

    // Check if the query is successful
    if (query.isActive()) {
        // Iterate over all records in the result set
        while (query.next()) {
            // Iterate over the columns and add them to the ComboBox
            int columnCount = query.record().count();
            for (int i = 0; i < columnCount; ++i) {
                QString value = query.value(i).toString();
                ui->niveau_cli_modif->addItem(value);
            }
        }
    } else {
        qDebug() << "Error fetching data from ROLE table:" << query.lastError().text() << query.lastError().databaseText();
    }


}





void client::modifier_client(Ui::MainWindow *ui){



QString id=ui->id_cli_modif->text();
 qDebug() << "zokom l id :"<<id;
        QSqlQuery query;
        query.prepare("UPDATE CLIENT SET NOM=:nom, PRENOM=:prenom, ADRESSE=:adresse, GENDER=:gender, MAIL=:mail, TEL=:tel, NIVEAU=:niveau, TYPE=:type, DOB=:dob WHERE ID=:id");
        query.bindValue(":id", id);
        query.bindValue(":tel", ui->tel_cli_modif->text().toInt());
        query.bindValue(":nom", ui->nom_cli_modif->text());
        query.bindValue(":prenom", ui->prenom_cli_modif->text());
        query.bindValue(":adresse", ui->adresse_cli_modif->text());
        query.bindValue(":gender", ui->gender_cli_modif->currentText());
        query.bindValue(":niveau", ui->niveau_cli_modif->currentText());
        query.bindValue(":type", ui->type_cli_modif->currentText());
        query.bindValue(":mail", ui->mail_cli_modif->text());
         query.bindValue(":dob", ui->dob_cli_modif->date());

        if (query.exec()) {

            afficher_client2(ui);
            afficher_client(ui);
            ui->client_supp->clear();
             ui->id_cli_modif->clear();
            ui->nom_cli_modif->clear();
            ui->prenom_cli_modif->clear();
            ui->mail_cli_modif->clear();
            ui->adresse_cli_modif->clear();
            ui->tel_cli_modif->clear();
            ui->dob_cli_modif->setDate(QDate::currentDate());
        } else {
            qDebug() << "Error updating data:" << query.lastError().text() << query.lastError().databaseText();
        }


}
void client::tri_cli(Ui::MainWindow *ui,QString choix) {

    int columnIndex=-1;

    if (choix == "Date de naissance")
        columnIndex=7;
    else if (choix == "PRENOM")
        columnIndex=1;
    else if (choix == "NOM")
        columnIndex=0;
    else if (choix == "MAIL")
        columnIndex=2;
    else if (choix == "ADRESSE")
        columnIndex=3;


    if (columnIndex != -1) {
        ui->tab_client->setSortingEnabled(false);

        ui->tab_client->sortByColumn(columnIndex, Qt::AscendingOrder);

        ui->tab_client->setSortingEnabled(true);

        ui->tab_client_2->setSortingEnabled(false);

        ui->tab_client_2->sortByColumn(columnIndex, Qt::AscendingOrder);

        ui->tab_client_2->setSortingEnabled(true);

        //afficher_employe2(ui);

        //qDebug() << "Table sorted by " << choix << " successfully.";
    } else {
        //qDebug() << choix << " column not found.";
    }
}
